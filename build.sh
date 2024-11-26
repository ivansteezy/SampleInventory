#! /bin/bash

echo "Starting build..."

cd build/

cmake --build .

cd -

echo "Build finished"