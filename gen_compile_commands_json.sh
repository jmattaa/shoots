#!/usr/bin/env bash

# generate compile_commands.json

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build
cp build/compile_commands.json .
