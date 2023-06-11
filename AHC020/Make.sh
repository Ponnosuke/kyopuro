#!/bin/bash

shopt -s expand_aliases

alias g++d='g++ -std=c++17 -fsanitize=undefined -Wall'
alias g++ld='g++ -std=c++17 -fsanitize=undefined -D LOCAL_DEBUG -Wall'

if [ $# -ne 2 ]; then
  echo "$0 \"int VERSION_NUMBER\" \"d or ld\""
  echo "For example: 5 d"
  exit 1
fi

if [[ "$1" =~ ^[^0-9]+$ ]]; then
  echo "$0 \"int VERSION_NUMBER\" \"d or ld\""
  echo "For example: 5 d"
  exit 1
fi

if [ "$2" != "d" ] && [ "$2" != "ld" ]; then
  $2="d"
fi

readonly TARGET_FILENAME="main_ver$1.cpp"
readonly OUTPUT_FILENAME="mv$1.out"

if [ ! -e $TARGET_FILENAME ]; then
  "$TARGET_FILENAME is not found."
  exit 1
fi

if [ "$2" = "d" ]; then
  g++d $TARGET_FILENAME -o $OUTPUT_FILENAME -O2
else
  g++ld $TARGET_FILENAME -o $OUTPUT_FILENAME -O2
fi

echo "compiled $TARGET_FILENAME to $OUTPUT_FILENAME"
exit 0