/*
    B - Enlarged Checker Board https://atcoder.jp/contests/abc250/tasks/abc250_b 

    各マスがどのタイルに属しているかを求めて、その座標の偶奇パリティで考える
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
    int N, A, B;
    cin >> N >> A >> B;

    for(int i = 0; i < A*N; i++){
        for(int j = 0; j < B*N; j++){
            int h = i / A, w = j / B;

            if((h + w) % 2 == 0){
                cout << ".";
            }
            else{
                cout << "#";
            }
        }
        cout << '\n';
    }
}