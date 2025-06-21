#Requires -Version 5
$ErrorActionPreference = "Stop"

$InstallDir = "$env:APPDATA\pug"
$ReleaseUrl = "https://github.com/yourorg/pug/releases/latest/download/pug-windows-x64.zip"

# Create installation directory
New-Item -ItemType Directory -Force -Path $InstallDir | Out-Null

# Download and extract release
Invoke-WebRequest $ReleaseUrl -OutFile "$env:TEMP\pug-latest.zip"
Expand-Archive -Path "$env:TEMP\pug-latest.zip" -DestinationPath $InstallDir -Force
Remove-Item "$env:TEMP\pug-latest.zip"

# Update user PATH
$PathVar = [Environment]::GetEnvironmentVariable("Path", "User")
if ($PathVar -notlike "*$InstallDir\bin*") {
    $NewPath = $PathVar + ";" + "$InstallDir\bin"
    [Environment]::SetEnvironmentVariable("Path", $NewPath, "User")
    $env:Path += ";$InstallDir\bin"
}

Write-Host "Pug installed to $InstallDir"
Write-Host "You may need to restart your shell for PATH changes to take effect"
