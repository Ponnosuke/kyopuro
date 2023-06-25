#!/bin/bash

if [ $# -ne 1 ]; then
  echo "For example: If you want to do \"code main_ver5.cpp\""
  echo "then  \"$0 5\""
  exit 1
fi
if [[ "$1" =~ ^[^0-9]+$ ]]; then
  echo "For example: If you want to do \"code main_ver5.cpp\""
  echo "then  \"$0 5\""
  exit 1
fi


CPP_FILE="main_ver${1}.cpp"

code ${CPP_FILE}