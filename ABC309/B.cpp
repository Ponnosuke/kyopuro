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
    debugP();


    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char ch;
            cin >> ch;

            if(ch == '0'){
                A.at(i).at(j) = 0;
            }
            else{
                A.at(i).at(j) = 1;
            }

            debugP();
        }
    }

    debugP();

    vector<vector<int>> B = A;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j == 0){
                if(i < N-1){
                    B.at(i).at(j) = A.at(i+1).at(j);
                }
                else{
                    B.at(i).at(j) = A.at(i).at(j+1);
                }
            }
            else if(j == N-1){
                if(i == 0){
                    B.at(i).at(j) = A.at(i).at(j-1);
                }
                else{
                    B.at(i).at(j) = A.at(i-1).at(j);
                }
            }
            else if(i == 0){
                B.at(i).at(j) = A.at(i).at(j-1);
            }
            else if(i == N-1){
                B.at(i).at(j) = A.at(i).at(j+1);
            }
        }
    }

    debugP();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << B.at(i).at(j);
        }
        cout << '\n';
    }

    return 0;
}