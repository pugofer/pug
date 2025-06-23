#Requires -Version 5.1
<#
.SYNOPSIS
    Pug Local Installer for Windows
.DESCRIPTION
    Downloads and installs Pug for the current user only.
    Usage: iwr -useb https://yoursite.com/install.ps1 | iex
#>

param(
    [string]$Version = "latest"
)

$ErrorActionPreference = "Stop"

# Configuration
$PROGRAM_NAME = "pug"
$GITHUB_REPO = "saukap/pugofer"  # Change this to your actual repo

# Colors for output (using Write-Host with colors)
function Write-Info {
    param([string]$Message)
    Write-Host "[INFO] $Message" -ForegroundColor Green
}

function Write-Warn {
    param([string]$Message)
    Write-Host "[WARN] $Message" -ForegroundColor Yellow
}

function Write-Error {
    param([string]$Message)
    Write-Host "[ERROR] $Message" -ForegroundColor Red
}

# Detect architecture and OS
function Get-Platform {
    $arch = $env:PROCESSOR_ARCHITECTURE
    $realArch = $env:PROCESSOR_ARCHITEW6432
    
    # Handle WOW64 (32-bit PowerShell on 64-bit Windows)
    if ($realArch) {
        $arch = $realArch
    }
    
    switch ($arch) {
        "AMD64" { $architecture = "x86_64" }
        "ARM64" { $architecture = "aarch64" }
        default { 
            Write-Error "Unsupported architecture: $arch"
            exit 1
        }
    }
    
    # We only support Windows
    $os = "Windows"
    
    return "${os}-${architecture}"
}

# Download package
function Get-Package {
    param(
        [string]$Platform
    )
    
    $packageName = "${PROGRAM_NAME}-${Platform}.zip"
    $tempDir = $env:TEMP
    $packagePath = Join-Path $tempDir $packageName
    
    if ($Version -eq "latest") {
        $packageUrl = "https://github.com/${GITHUB_REPO}/releases/latest/download/${packageName}"
    } else {
        $packageUrl = "https://github.com/${GITHUB_REPO}/releases/download/${Version}/${packageName}"
    }
    
    Write-Info "Downloading ${PROGRAM_NAME} package from ${packageUrl}"
    
    try {
        # Use TLS 1.2 for compatibility
        [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
        Invoke-WebRequest -Uri $packageUrl -OutFile $packagePath -UseBasicParsing
    }
    catch {
        Write-Error "Failed to download package: $($_.Exception.Message)"
        exit 1
    }
    
    if (-not (Test-Path $packagePath) -or (Get-Item $packagePath).Length -eq 0) {
        Write-Error "Failed to download package or package is empty"
        exit 1
    }
    
    return $packagePath
}

# Install everything
function Install-Pug {
    $platform = Get-Platform
    
    Write-Info "Installing ${PROGRAM_NAME} for ${platform}"
    
    # Create directories in user's local app data
    $installDir = Join-Path $env:LOCALAPPDATA "Programs\${PROGRAM_NAME}"
    $binDir = Join-Path $installDir "bin"
    $shareDir = Join-Path $installDir "share\${PROGRAM_NAME}"
    
    Write-Info "Installing to: $installDir"
    
    New-Item -ItemType Directory -Force -Path $binDir | Out-Null
    New-Item -ItemType Directory -Force -Path $shareDir | Out-Null
    
    # Create temporary directory for extraction
    $tempExtractDir = Join-Path $env:TEMP "pug-install-$(Get-Random)"
    New-Item -ItemType Directory -Force -Path $tempExtractDir | Out-Null
    
    try {
        # Download and extract package
        $packagePath = Get-Package -Platform $platform
        
        Write-Info "Extracting package"
        Expand-Archive -Path $packagePath -DestinationPath $tempExtractDir -Force
        
        # Find the extracted directory (e.g., pug-1.0.0-Windows, etc.)
        $extractedDirs = Get-ChildItem -Path $tempExtractDir -Directory | Where-Object { $_.Name -like "pug-*" }
        
        if ($extractedDirs.Count -eq 0) {
            Write-Error "Could not find extracted pug directory"
            exit 1
        }
        
        $extractedDir = $extractedDirs[0].FullName
        Write-Info "Found extracted directory: $($extractedDirs[0].Name)"
        
        # Install binary
        $binaryPath = Join-Path $extractedDir "bin\${PROGRAM_NAME}.exe"
        if (Test-Path $binaryPath) {
            $targetBinaryPath = Join-Path $binDir "${PROGRAM_NAME}.exe"
            Copy-Item -Path $binaryPath -Destination $targetBinaryPath -Force
            Write-Info "Binary installed to $targetBinaryPath"
        } else {
            Write-Error "Binary '${PROGRAM_NAME}.exe' not found at $binaryPath"
            exit 1
        }
        
        # Install langlevels folder
        $langlevelsPath = Join-Path $extractedDir "share\pug\langlevels"
        if (Test-Path $langlevelsPath -PathType Container) {
            $targetLanglevelsPath = Join-Path $shareDir "langlevels"
            Copy-Item -Path $langlevelsPath -Destination $targetLanglevelsPath -Recurse -Force
            Write-Info "Language levels installed to $targetLanglevelsPath"
        } else {
            Write-Error "Directory 'langlevels' not found at $langlevelsPath"
            exit 1
        }
        
        # Clean up downloaded package
        Remove-Item $packagePath -Force -ErrorAction SilentlyContinue
        
        Write-Info "Successfully installed ${PROGRAM_NAME}"
        
        # Update user PATH
        $userPath = [Environment]::GetEnvironmentVariable("Path", "User")
        if ($userPath -notlike "*$binDir*") {
            Write-Info "Adding $binDir to user PATH"
            
            # Clean up the path string and add our directory
            $newPath = if ($userPath) { 
                $userPath.TrimEnd(';') + ";$binDir" 
            } else { 
                $binDir 
            }
            
            [Environment]::SetEnvironmentVariable("Path", $newPath, "User")
            
            # Also update the current session PATH
            $env:Path += ";$binDir"
            
            Write-Info "PATH updated successfully"
            Write-Warn "You may need to restart your terminal/PowerShell session for PATH changes to take effect in new sessions"
        } else {
            Write-Info "$binDir is already in your PATH"
        }
        
        Write-Info "You can now run: ${PROGRAM_NAME}"
        Write-Info "Installation directory: $installDir"
        
    }
    finally {
        # Clean up temporary extraction directory
        if (Test-Path $tempExtractDir) {
            Remove-Item $tempExtractDir -Recurse -Force -ErrorAction SilentlyContinue
        }
    }
}

# Test if running as administrator
function Test-Administrator {
    $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($currentUser)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

# Main execution
function Main {
    Write-Info "Starting ${PROGRAM_NAME} installation"
    
    # Check if running as administrator (we want user-level install)
    if (Test-Administrator) {
        Write-Warn "Running as Administrator detected"
        Write-Info "This installer performs a user-level installation and doesn't require administrator privileges"
        Write-Info "Consider running this script as a regular user for a cleaner user-specific installation"
    }
    
    # Check PowerShell version
    if ($PSVersionTable.PSVersion.Major -lt 5) {
        Write-Error "PowerShell 5.1 or later is required. Current version: $($PSVersionTable.PSVersion)"
        exit 1
    }
    
    Install-Pug
    
    Write-Info "Installation complete!"
    Write-Info ""
    Write-Info "Next steps:"
    Write-Info "1. Open a new PowerShell session or restart your terminal"
    Write-Info "2. Run '${PROGRAM_NAME}' to start using Pug"
}

# Execute main function
try {
    Main
}
catch {
    Write-Error "Installation failed: $($_.Exception.Message)"
    Write-Error "Please check the error details above and try again"
    exit 1
}
