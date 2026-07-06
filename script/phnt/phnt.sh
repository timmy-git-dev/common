set -e

readonly PATH_PARSER="script/phnt/Parser.cpp"
readonly PATH_BIN="script/bin/phnt"
readonly PATH_PHNT="$PATH_BIN/repo"
readonly PATH_OUT="$PATH_BIN/Main.out"

mkdir -p "$PATH_BIN"
rm -rf "$PATH_PHNT"

# git clone https://github.com/apple-oss-distributions/xnu.git /path/to/folder
git clone "https://github.com/winsiderss/phnt.git" "$PATH_PHNT"

clang++ "$PATH_PARSER" -std=c++23 -lclang -o "$PATH_OUT"
$PATH_OUT