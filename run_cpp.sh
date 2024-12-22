#!/bin/bash

# Check if a source file is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <source_file.cpp> [--allow-warnings]"
    exit 1
fi

# Get the source file and validate its existence
SOURCE_FILE="$1"
if [[ ! "$SOURCE_FILE" == *.cpp ]]; then
    echo "Error: First argument must be a .cpp file."
    exit 1
fi
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: File '$SOURCE_FILE' not found."
    exit 1
fi

# Check for the --allow-warnings flag as the second argument
ALLOW_WARNINGS=false
if [ "$2" == "--allow-warnings" ]; then
    ALLOW_WARNINGS=true
elif [ -n "$2" ]; then
    echo "Error: Invalid second argument. Use '--allow-warnings' or leave it empty."
    exit 1
fi

# Extract directory and base name
SOURCE_DIR=$(dirname "$SOURCE_FILE")
BASE_NAME=$(basename "$SOURCE_FILE" .cpp)

# Change to the directory of the source file
cd "$SOURCE_DIR" || { echo "Error: Cannot access directory $SOURCE_DIR"; exit 1; }

# Compile command with or without -Werror
CLANG_FLAGS="-mmacosx-version-min=13.0 -o \"$BASE_NAME\" -ggdb -O0 \
    -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -std=c++20"

if [ "$ALLOW_WARNINGS" == false ]; then
    CLANG_FLAGS="$CLANG_FLAGS -Werror"
fi

# Compile and run the program
eval clang++ $CLANG_FLAGS \"$BASE_NAME.cpp\" && ./"$BASE_NAME"
