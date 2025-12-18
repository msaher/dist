#!/bin/sh

LIBS="$(pkg-config --libs gsl)"

gcc $LIBS -Wall -Wextra main.c -o dist
