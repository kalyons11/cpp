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

# Find all .cpp files in the same directory as the source file
CPP_FILES=$(find . -maxdepth 1 -name "*.cpp")

# Auto-fix issues with clang-tidy for each .cpp file
echo "Running clang-tidy with auto-fix on all .cpp files..."
for CPP_FILE in $CPP_FILES; do
    echo "Analyzing and fixing $CPP_FILE with clang-tidy..."
    clang-tidy "$CPP_FILE" -fix -fix-errors -- -std=c++20 || exit 1
done

# Auto-fix style issues with clang-format for each .cpp file
echo "Running clang-format to auto-format all .cpp files..."
for CPP_FILE in $CPP_FILES; do
    echo "Formatting $CPP_FILE with clang-format..."
    clang-format -i "$CPP_FILE" || exit 1
done

# Compile command with or without -Werror
CLANG_FLAGS="-mmacosx-version-min=13.0 -c -g -O0 \
    -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -std=c++20"

if [ "$ALLOW_WARNINGS" == false ]; then
    CLANG_FLAGS="$CLANG_FLAGS -Werror"
fi

# Compile all .cpp files into object files
for CPP_FILE in $CPP_FILES; do
    OBJ_FILE=$(basename "$CPP_FILE" .cpp).o
    echo "Compiling $CPP_FILE to $OBJ_FILE..."
    eval clang++ $CLANG_FLAGS "$CPP_FILE" -o "$OBJ_FILE" || exit 1
done

# Link the object files into an executable
echo "Linking object files into $BASE_NAME..."
eval clang++ -o $CLANG_FLAGS "$BASE_NAME".o *.o || exit 1

# Set up debug symbols
dsymutil ./"$BASE_NAME".o

# Run the program
echo "Running $BASE_NAME..."
./"$BASE_NAME".o
