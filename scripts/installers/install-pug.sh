#!/bin/bash
set -e

# Pug Local Installer
# Usage: curl -LsSf https://yoursite.com/install.sh | sh

PROGRAM_NAME="pug"
GITHUB_REPO="saukap/pugofer"  # Change this to your actual repo
VERSION="latest"  # or specify a version like "v1.0.0"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Helper functions
log_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

log_warn() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Detect architecture and OS
detect_platform() {
    local arch
    local os
    
    case $(uname -m) in
        x86_64) arch="x86_64" ;;
        aarch64|arm64) arch="aarch64" ;;
        *) log_error "Unsupported architecture: $(uname -m)"; exit 1 ;;
    esac
    
    case $(uname -s) in
        Linux) os="linux" ;;
        *) log_error "Unsupported OS: $(uname -s)"; exit 1 ;;
    esac
    
    echo "${os}-${arch}"
}

# Download package
download_package() {
    local platform=$1
    local package_url
    local package_name="${PROGRAM_NAME}-${platform}.tar.gz"
    
    if [ "$VERSION" = "latest" ]; then
        package_url="https://github.com/${GITHUB_REPO}/releases/latest/download/${package_name}"
    else
        package_url="https://github.com/${GITHUB_REPO}/releases/download/${VERSION}/${package_name}"
    fi
    
    log_info "Downloading ${PROGRAM_NAME} package from ${package_url}"
    
    if command -v curl >/dev/null 2>&1; then
        curl -LsSf "$package_url" -o "$package_name"
    elif command -v wget >/dev/null 2>&1; then
        wget -q "$package_url" -O "$package_name"
    else
        log_error "Neither curl nor wget found. Please install one of them."
        exit 1
    fi
    
    if [ ! -f "$package_name" ] || [ ! -s "$package_name" ]; then
        log_error "Failed to download package"
        exit 1
    fi
    
    echo "$package_name"
}

# Install everything
install_pug() {
    local platform
    platform=$(detect_platform)
    
    log_info "Installing ${PROGRAM_NAME} for ${platform}"
    
    # Create directories
    mkdir -p "$HOME/.local/bin"
    mkdir -p "$HOME/.local/share/${PROGRAM_NAME}"
    
    # Create temporary directory
    local temp_dir
    temp_dir=$(mktemp -d)
    cd "$temp_dir"
    
    # Download and extract package
    local package_name
    package_name=$(download_package "$platform")
    
    log_info "Extracting package"
    tar -xzf "$package_name"
    
    # Install binary
    if [ -f "$PROGRAM_NAME" ]; then
        chmod +x "$PROGRAM_NAME"
        mv "$PROGRAM_NAME" "$HOME/.local/bin/"
        log_info "Binary installed to ~/.local/bin/${PROGRAM_NAME}"
    else
        log_error "Binary '${PROGRAM_NAME}' not found in package"
        exit 1
    fi
    
    # Install langlevels folder
    if [ -d "langlevels" ]; then
        cp -r langlevels "$HOME/.local/share/${PROGRAM_NAME}/"
        log_info "Language levels installed to ~/.local/share/${PROGRAM_NAME}/langlevels/"
    else
        log_error "Directory 'langlevels' not found in package"
        exit 1
    fi
    
    # Clean up
    cd "$HOME"
    rm -rf "$temp_dir"
    
    log_info "Successfully installed ${PROGRAM_NAME}"
    
    # Check if ~/.local/bin is in PATH
    if [[ ":$PATH:" != *":$HOME/.local/bin:"* ]]; then
        log_warn "~/.local/bin is not in your PATH"
        log_info "Add this line to your ~/.bashrc or ~/.zshrc:"
        echo "    export PATH=\"\$HOME/.local/bin:\$PATH\""
        log_info "Then run: source ~/.bashrc (or restart your terminal)"
    else
        log_info "You can now run: ${PROGRAM_NAME}"
    fi
}

# Main execution
main() {
    log_info "Starting ${PROGRAM_NAME} installation"
    
    # Check if running as root
    if [ "$EUID" -eq 0 ]; then
        log_error "Don't run this installer as root - it installs to ~/.local"
        exit 1
    fi
    
    install_pug
    
    log_info "Installation complete!"
}

main "$@"