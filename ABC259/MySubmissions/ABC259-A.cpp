#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    vector<int> Tlen(N + 1, 0);

    // cout << "X = " << X << endl;

    for(int i = N; i >= 0; i--){
        if(i == N){
            Tlen.at(i) = T;

            // debug
            // cout << i << "first" << endl;
        }
        else if((X <= i) && (i < N)){
            Tlen.at(i) = T;

            // debug
            // cout << X << " "  << i << " " << N << "second" << endl;
        }
        else{
            Tlen.at(i) = Tlen.at(i + 1) - D;

            // debug
            // cout << i << "third" << endl;
        }
    }

    // debug
    /*
    for(int i = 0; i <= N; i++){
        cout << i << " " << Tlen.at(i) << endl;
    }
    */

   cout << Tlen.at(M) << endl;
}