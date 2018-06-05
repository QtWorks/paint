#!/bin/bash

cd ./src
make clean
qmake ./paint.pro -r -spec linux-g++-64
make -j
make -j clean
cd ..
cp ./src/paint .
