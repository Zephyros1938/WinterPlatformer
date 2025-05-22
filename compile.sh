#!/bin/bash

set -e

BUILD_DIR="build"

# Create build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Run CMake and build
cmake ..
make -j$(nproc)

# Optional: Run the app if build succeeds
echo "Build complete."
# ./WindowApp
