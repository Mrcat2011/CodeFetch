# C++ Profile Fetcher

A CLI tool written in C++ to fetch and display user statistics from competitive programming platforms.

## ⚠️ Disclaimer
**NOTE:** The installation script were assisted by AI. It may not work on every system configuration. Use it at your own risk.

## Prerequisites
This project requires `libcurl` and `nlohmann-json`. 

### Automatic Installation (Arch & Ubuntu)
We provide an `install.sh` script to handle dependencies:
```bash
chmod +x install.sh
./install.sh

//For build
make

./profile <sitename> <handle>

Example
./profile codeforces programmercat

 ┌──────────────────────────────────────────────────────────┐
  👤 specialist programmercat
 ├──────────────────────────────────────────────────────────┤
  📇 Full name:    Mrcat Mcrat
  🚩 From:         Azerbaijan
  📈 Rating:       1587 (max. 1606, specialist)
  🌟 Contribution: +15
 └──────────────────────────────────────────────────────────┘


Platform,Status
Codeforces,✅ Supported
Others,🚧 Coming Soon
