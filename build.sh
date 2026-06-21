#!/usr/bin/env bash
# Build script that uses the existing CMakePresets.json
# Usage: ./build.sh [preset]

PRESET=${1:-x64-release}

echo "Configuring with preset ${PRESET}..."
cmake --preset "${PRESET}" || exit $?

echo "Building with preset ${PRESET}..."
cmake --build --preset "${PRESET}" || exit $?

exit 0
