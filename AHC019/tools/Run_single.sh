#!/bin/bash

# option $3 = cat

if [ $# -ne 2 ] && [ $# -ne 3 ]; then
  echo "$0 \"string EXE_FILENAME(exclude .out)\" \"int INPUT_TEXT_NUM\""
  echo "For example: $0 mv5 15"
  exit 1
fi
if [[ "$1" == *.out* ]]; then
  echo ".out isn't needed"
  echo "For example: $0 mv5 15"
  exit 1
fi  

readonly EXE_FILENAME="$1.out"
readonly TEXT_NUM=$2

if [ ! -e "../$EXE_FILENAME" ]; then
  echo "$EXE_FILENAME is not found."
  exit 1
fi
if [[ "$TEXT_NUM" =~ ^[^0-9]+$ ]]; then
  echo "$0 \"string EXE_FILENAME(exclude .out)\" \"int INPUT_TEXT_NUM\""
  echo "For example: $0 mv5 15"
  exit 1
fi

readonly DIR_NAME=$1
readonly INPUT_TEXTNUM=$(printf "%04d\n" "$TEXT_NUM")
readonly OUT_TEXTNAME="${1}_${INPUT_TEXTNUM}out"
readonly LOG_TEXTNAME="${1}_${INPUT_TEXTNUM}log"

if [ ! -e "./in/${INPUT_TEXTNUM}.txt" ]; then
  echo "${INPUT_TEXTNUM}.txt is not found."
  exit 1
fi

if [ ! -d "./out/$DIR_NAME" ]; then
  mkdir -p ./out/$DIR_NAME
fi
if [ ! -d "./log/${DIR_NAME}" ]; then
  mkdir -p ./log/${DIR_NAME}
fi

../"$EXE_FILENAME" <./in/"${INPUT_TEXTNUM}.txt" >./out/"$DIR_NAME"/"${OUT_TEXTNAME}.txt"

cargo run --release --bin vis ./in/"${INPUT_TEXTNUM}.txt" ./out/"$DIR_NAME"/"${OUT_TEXTNAME}.txt" 1>./log/${DIR_NAME}/"${LOG_TEXTNAME}.txt"

if [ "$3" = "cat" ];then
  cat ./log/${DIR_NAME}/"${LOG_TEXTNAME}.txt"
fi

exit 0