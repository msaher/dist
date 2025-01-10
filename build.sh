#!/bin/sh

LIBS="$(pkg-config --libs gsl)"

gcc $LIBS -Wall -Wextra main2.c -o dist2
