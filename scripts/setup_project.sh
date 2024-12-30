#!/bin/bash

# Check if PROJECT_NAME, FILE_NAME, and FUNCTION_NAME are provided
if [ $# -ne 3 ]; then
    echo "Usage: $0 PROJECT_NAME FILE_NAME FUNCTION_NAME"
    exit 1
fi

PROJECT_NAME=$1
FILE_NAME=$2
FUNCTION_NAME=$3

# if the project name already exists, exit
if [ -d "$PROJECT_NAME" ]; then
    echo "Project $PROJECT_NAME already exists"
    exit 1
fi

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

./scripts/setup_file.sh "$PROJECT_NAME/$FILE_NAME" "$FUNCTION_NAME"

./run_cpp.sh "$PROJECT_NAME/main.cpp"

# Show the run command for the user
echo "To run the project, use the following command:"
echo ""
COMMAND="clear && ./run_cpp.sh $PROJECT_NAME/main.cpp"
echo "$COMMAND"

# Copy that command to their clipboard
echo "$COMMAND" | pbcopy
