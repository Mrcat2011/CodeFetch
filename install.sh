#!/bin/bash

###############################################################################
# NOTE: This install script was partially generated/assisted by AI.
# WARNING: While it is designed for Arch and Ubuntu, it may not work on all 
# system configurations. Use it at your own risk. Always review scripts 
# before running them with sudo.
###############################################################################


set -e

echo "Starting dependency installation..."

if [ -f /etc/arch-release ]; then
    echo "Detected Arch Linux."
    sudo pacman -Syu --needed --noconfirm curl nlohmann-json base-devel

elif [ -f /etc/lsb-release ] || [ -f /etc/debian_version ]; then
    echo "Detected Ubuntu/Debian."
    sudo apt update
    sudo apt install -y libcurl4-openssl-dev nlohmann-json3-dev build-essential

else
    echo "Unsupported distribution."
    echo "Please manually install libcurl and nlohmann-json."
    exit 1
fi

echo "------------------------------------------"
echo "Installation completed successfully!"
echo "------------------------------------------"