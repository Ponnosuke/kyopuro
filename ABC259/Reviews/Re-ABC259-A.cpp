/*
わかりにくい時は図を描いてみる
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    if(X <= M){
        cout << T << endl;
    }
    else{
        cout << T - D*(X-M) << endl;
    }
}