#!/usr/bin/env bash
find . -type f -name "*$1" -print0 |
while IFS= read -r -d '' file; do
    mv -- "$file" "${file%$1}$2"
done