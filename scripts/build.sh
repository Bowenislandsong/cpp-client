#!/bin/bash

# Based on https://github.com/codecov/example-cpp11-cmake/blob/master/run_build.sh.

RED='\033[0;31m'
BLUE='\033[0;34m'
NO_COLOR='\033[0m'
GREEN='\033[0;32m'

function error() {
    >&2 echo -e "${RED}$1${NO_COLOR}"
}

function info() {
    echo -e "${GREEN}$1${NO_COLOR}"
}

function working() {
    echo -e "${BLUE}$1${NO_COLOR}"
}

function alert() {
    echo -e "${RED}$1${NO_COLOR}"
}

mkdir -p build
cd build || exit
cmake -DCMAKE_BUILD_TYPE=Debug ..
if make -j3; then
    true
else
    error "Error: compilation errors"
    exit 3
fi

info "Running tests..."
make -j3 UnitTest
if ctest; then
    true
else
    error "Error: test failure"
fi

working "All tests compiled and passed"
