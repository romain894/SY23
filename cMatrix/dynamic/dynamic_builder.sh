#!/bin/bash

cd src
echo "Cleaning files"
make clean
make all
make lib
echo "Created .o and .so files"
cd ..
cd build
make clean
make all
export LD_LIBRARY_PATH=../lib
./main
