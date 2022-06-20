#!/bin/sh

mkdir build
cp test/test0.c build/
cd build 
cmake ..
make 
./cc test0.c
