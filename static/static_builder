#!/bin/bash

cd src
echo "Cleaning files"
make clean
echo "Creating o. and a. files"
make all
make lib
cd ../build/
echo "Building main exec"
make clean
make all
./main
