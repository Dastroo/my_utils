#!/bin/bash
cd build || (mkdir build && cd build || exit)
cmake ..
make
sudo make install