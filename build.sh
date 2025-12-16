#!/bin/bash
rm -rd build
cmake -S . -B build/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build/
