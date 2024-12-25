#!/bin/bash

# Default flags for compiling and linking with debug symbols
CLANG_FLAGS="-mmacosx-version-min=13.0 -g -O0 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -std=c++20"

run_cpp() {
  if [ -z "$1" ]; then
    echo "Error: No source file provided."
    exit 1
  fi

  SOURCE_FILE="$1"
  SOURCE_DIR=$(dirname "$SOURCE_FILE")
  BASE_NAME=$(basename "$SOURCE_FILE" .cpp)
  EXECUTABLE_FILE="$BASE_NAME.out"

  echo "Changing to source directory: $SOURCE_DIR"
  cd "$SOURCE_DIR" || { echo "Error: Failed to change directory to '$SOURCE_DIR'."; exit 1; }

  # Find all .cpp files in the same directory as the source file
  CPP_FILES=$(find . -maxdepth 1 -name "*.cpp")

  # Compile and link all .cpp files in one step
  echo "Compiling and linking all .cpp files into executable: $EXECUTABLE_FILE"
  clang++ $CLANG_FLAGS $CPP_FILES -o "$EXECUTABLE_FILE"
  if [ $? -ne 0 ]; then
    echo "Error: Compilation and linking failed."
    exit 1
  fi

  echo "Executable generated: $SOURCE_DIR/$EXECUTABLE_FILE"

  # Run the program
  echo "Running the program..."
  ./$EXECUTABLE_FILE
}

run_cpp "$@"
