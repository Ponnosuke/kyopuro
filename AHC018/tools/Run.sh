#!/bin/bash

# option $4 = cat or none

if [ $# -ne 3 ] && [ $# -ne 4 ]; then
  echo "$0 \"string EXE_FILENAME\" \"int LOOP_CNT_LOWER\" \"int LOOP_CNT_UPPER\""
  echo "For example: $0 mv5 0 49"
  exit 1
fi

readonly EXE_FILENAME="$1.out"
readonly LOOP_CNT_LOWER=$2
readonly LOOP_CNT_UPPER=$3

if [ ! -e "../$EXE_FILENAME" ]; then
  echo "$EXE_FILENAME is not found."
  exit 1
fi
if [[ "$LOOP_CNT_LOWER" =~ ^[^0-9]+$ ]] || [[ "$LOOP_CNT_UPPER" =~ ^[^0-9]+$ ]]; then
  echo "$0 \"string EXE_FILENAME\" \"int LOOP_CNT_LOWER\" \"int LOOP_CNT_UPPER\""
  echo "For example: $0 mv5 0 49"
  exit 1
fi
if [ ${LOOP_CNT_LOWER} -gt ${LOOP_CNT_UPPER} ]; then
  echo "ERROR: LOOP_CNT_LOWER > LOOP_CNT_UPPER"
  exit 1
fi
if [ ! -e "./Run_single.sh" ]; then
  echo "./Run_single.sh is not found."
  exit 1
fi

if [ -e "./${1}_RESULT.txt" ]; then
  rm "./${1}_RESULT.txt"
fi

score_sum=0

for index in `seq ${LOOP_CNT_LOWER} ${LOOP_CNT_UPPER}`
do
  TEXTNAME=$(printf "%04d\n" "${index}")
  if [ "$4" = "cat" ]; then
    ./Run_single.sh ${1} ${index} cat
  else
    ./Run_single.sh ${1} ${index}
  fi

  score_tmp=$(grep "Total Cost = " ./log/${1}/"${1}_${TEXTNAME}log.txt" | sed -e 's/[^0-9]//g')


  if [ "$score_tmp" = "" ];then
    echo "DEBUG: score_tmp = ${score_tmp}"
    echo "index = ${index}"
    echo "TEXTNAME = ${TEXTNAME}"
  fi


  if [ "$score_tmp" = "" ]; then
    echo "ERROR: Score isn't found."
    exit 1
  fi


  score_sum=$((${score_sum}+${score_tmp}))
  if [ "$4" != "cat" ] && [ "$4" != "none" ]; then
    echo "${TEXTNAME}.txt  SCORE = ${score_tmp}" >>./"${1}_RESULT.txt"
    echo "${TEXTNAME}.txt  SCORE = ${score_tmp}"
  fi 
done

input_cnt=$((${LOOP_CNT_UPPER}-${LOOP_CNT_LOWER}+1))
score_ave=$((${score_sum}/${input_cnt}))

{
  echo ""
  echo "SCORE:"
  echo "SUM = ${score_sum}"
  echo "AVERAGE = ${score_ave}"
} >>./"${1}_RESULT.txt"

# >./log/${1}/"${1}_RESULT.txt"

echo "SCORE:"
echo "SUM = ${score_sum}"
echo "AVERAGE = ${score_ave}"

echo "Finish"

exit 0








exit 0