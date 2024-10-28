#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Get the directory of the script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Navigate to the project root directory
cd "$SCRIPT_DIR/.."

# Define the build directory
BUILD_DIR="build"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Run cmake to configure the project
cmake -DGENERATE_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -B "$BUILD_DIR"

# Build the project
cmake --build "$BUILD_DIR"

