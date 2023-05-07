/*
    コンパイルコマンド
    g++ld fileName.cpp
        g++LocalDebug の略

    alias g++ld='g++ -std=c++17 -fsanitize=undefined -I /mnt/d/Users/tmtm_/GithubRepos/AtCoder/Library/ac-library -Wall -D LOCAL_DEBUG'

    debug(X): そのまま変数の値を出力。配列とかの中身を確認する用
    debugV(X): debugVariable() の略。Console.Write() のノリ。
    debugVL(Y):  debugVariableLine() の略 Console.WriteLine() のノリ
    debugWL(Z):  debugWriteLine() の略。 これも Console.WriteLine() のノリ。
    debugP():  debugPoint() の略。 書いた行番号を出力する
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int test1 = 3;
    double test2 = 3.14;

    debugP();

    cout << "start" << endl;
    debugV(test1);
    debugVL(test2);
    debugWL(pointA);
    cout << "end" << endl;

    debugP();

    return 0;
}