set -e

readonly PATH_BIN="script/bin/xnu"
readonly PATH_PARSER="script/xnu/xnu.cpp"
readonly PATH_XNU="$PATH_BIN/repo"
readonly PATH_OUT="$PATH_BIN/xnu.out"

mkdir -p "$PATH_BIN"

# git clone https://github.com/apple-oss-distributions/xnu.git "$PATH_XNU"

clang++ "$PATH_PARSER" -O3 -std=c++23 -lclang -o "$PATH_OUT"
$PATH_OUT