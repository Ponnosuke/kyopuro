#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<vector<char>> A(N,vector<char>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }

    bool isCorrect = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)  continue;

            char aij = A.at(i).at(j), aji = A.at(j).at(i);
            if(aij == 'W' && aji != 'L'){
                isCorrect = false;
                break;
            }
            if(aij == 'L' && aji != 'W'){
                isCorrect = false;
                break;
            }
            if(aij == 'D' && aij != 'D'){
                isCorrect = false;
                break;
            }
        }

        if(!(isCorrect))  break;
    }

    if(isCorrect){
        cout << "correct" << endl;
    }
    else{
        cout << "incorrect" << endl;
    }
}