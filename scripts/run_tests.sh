#!/bin/bash

# Get the directory of the script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Navigate to the project root directory
cd "$SCRIPT_DIR/.."

# Run the build_tests script
./scripts/build_tests.sh

# Check if the build was successful
if [ $? -eq 0 ]; then
    # Launch the dm_math_tests binary
    ./build_tests/bin/dm_math_tests
else
    echo "Build failed. Please check the build_tests script for errors."
    exit 1
fi