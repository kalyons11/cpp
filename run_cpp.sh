#!/bin/bash

# Check if a source file is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <source_file.cpp>"
    exit 1
fi

# Get the full path and directory of the source file
SOURCE_FILE="$1"
SOURCE_DIR=$(dirname "$SOURCE_FILE")
BASE_NAME=$(basename "$SOURCE_FILE" .cpp)

# Change to the directory of the source file
cd "$SOURCE_DIR" || { echo "Error: Cannot access directory $SOURCE_DIR"; exit 1; }

# Compile and run the program
clang++ -mmacosx-version-min=13.0 -o "$BASE_NAME.o" -ggdb -O0 \
    -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion \
    -Werror -std=c++20 "$BASE_NAME.cpp" && ./"$BASE_NAME.o"
