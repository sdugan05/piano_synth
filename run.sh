#!/bin/bash

cd build
cmake ../
cmake --build .
./piano_synth
