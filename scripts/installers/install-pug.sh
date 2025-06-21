#!/bin/bash
set -e

INSTALL_DIR="$HOME/.local/pug"
RELEASE_URL="https://github.com/yourorg/pug/releases/latest/download/pug-linux-x64.tar.gz"

# Verify dependencies
if ! command -v curl &> /dev/null; then
    echo "Error: curl is required to download releases"
    exit 1
fi

echo "Installing Pug to $INSTALL_DIR"
mkdir -p "$INSTALL_DIR"
curl -L "$RELEASE_URL" | tar xz -C "$INSTALL_DIR" --strip-components=1

# Add to PATH if not already present
if [[ ":$PATH:" != *":$INSTALL_DIR/bin:"* ]]; then
    echo "Adding Pug to your PATH"
    echo "export PATH=\"\$PATH:$INSTALL_DIR/bin\"" >> "$HOME/.bashrc"
    echo "export PATH=\"\$PATH:$INSTALL_DIR/bin\"" >> "$HOME/.profile"
    export PATH="$PATH:$INSTALL_DIR/bin"
fi

echo "Installation complete! Restart your shell or run:"
echo "  source ~/.bashrc"
