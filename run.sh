if [[ "$1" == "lin" ]]; then
    ./build/lin.sh x86_64-pc-linux-gnu
elif [[ "$1" == "mac" ]]; then
    ./build/mac.sh arm64-apple-darwin
elif [[ "$1" == "win" ]]; then
    pwsh build/win.ps1 x86_64-w64-windows-gnu
fi