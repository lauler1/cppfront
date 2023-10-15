#!/bin/bash

export CPPFRONTDIR="$(pwd)/cppfront"
alias cppfront=$CPPFRONTDIR/cppfront

echo "export CPPFRONTDIR=$CPPFRONTDIR"
echo "Alias = " $(alias cppfront)
