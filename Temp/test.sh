#!/bin/bash

shopt -s expand_aliases

alias g++d='g++ -std=c++17 -fsanitize=undefined -Wall'

if [ $# -eq 0 ]; then
  read num1
else
  num1=$1
fi

echo $num1


read str
HELLO_FILENAME="$str.cpp"
if [ -e "./$HELLO_FILENAME" ]; then
  g++d $HELLO_FILENAME -o $str.out
else
  echo "The file isn't found."
  exit 1
fi

EXE_FILENAME="$str.out"

if [ -e "./$EXE_FILENAME" ]; then
  ./"$str.out"
else
  echo "$str.out is not found."
  exit 1
fi

echo "finish"

exit 0