#!/bin/bash

CC sdl_test.c -o sdl_test `sdl2-config --cflags --libs`
git clone git@github.com:phdenzel/c-std.git
CC sdl_runtime.c -o sdl_runtime `sdl2-config --cflags --libs`
