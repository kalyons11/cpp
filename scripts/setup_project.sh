#!/bin/bash

# Check if PROJECT_NAME is provided
if [ -z "$1" ]; then
    echo "Usage: $0 PROJECT_NAME"
    exit 1
fi

PROJECT_NAME=$1

# Create the project directory
mkdir -p "$PROJECT_NAME"

# Create the main.cpp file with the sample code
cat <<EOL > "$PROJECT_NAME/main.cpp"
#include <iostream>

int main() {
    std::cout << "Hello, this is a sample message from project: " << "$PROJECT_NAME" << '\n';
    return 0;
}
EOL

echo "Project $PROJECT_NAME has been set up with main.cpp"

./scripts/setup_file.sh "$PROJECT_NAME/sample" "sample_function"

./run_cpp.sh "$PROJECT_NAME/main.cpp"
