#!/bin/bash

pip install -e .
mv ./*.so src/ext/bin
rm -r ./build

cilen
