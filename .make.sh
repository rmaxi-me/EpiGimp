#!/bin/bash

cmake . -B ./build $1 && cmake --build ./build -j $(nproc --all)
