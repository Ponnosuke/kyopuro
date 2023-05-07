#!/bin/bash

# "./beginContest.sh" ではなく ". beginContest.sh" で実行する

for index in {0..2}
do
    echo "Enter a name of a contest: "
    read contestName

    echo "Is this name correct? [Y/n] -> ${contestName}: "
    read answer

    flag=2
    if [ "$answer" == "Y" ]; then
        flag=1
        break
    elif [ "$answer" == "n" ]; then
        if [ $index -eq 2 ]; then
            break
        fi

        echo "Shall we continue? [Y/n]"
        read answer2
        if [ "$answer2" == "Y" ]; then
            continue
        elif [ "$answer2" == "n" ]; then
            flag=0
            break
        else
            break
        fi
    else
        echo "You enter a wrong character"
        echo "Enter Y or n : "
        read answer
    fi
done

if [ $flag -eq 1 ]; then
    if [ ! -d "./${contestName}" ]; then
        mkdir -p ./"$contestName"
    fi
    cd "./${contestName}"
    touch A.cpp
    cd ../
    code "./${contestName}/A.cpp"
    cd "./${contestName}"

    echo ""
    echo ""
    echo "NOTE: Don't forget to set the language to 'C++ (GCC x.x.x)' !"
    echo ""
    echo ""
    # echo "You ready for ${contestName}? Okay, good luck!!"
elif [ $flag -eq 0 ]; then
    echo "Okay, we'll see you again! Bye-bye!!"
else
    echo "Oops! You've made a lot of mistakes!! Please try again!!!"
fi