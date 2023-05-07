/*
    愚直解
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int query;
        cin >> query;

        if(query == 1){
            i64 x;
            cin >> x;
            vector<i64> tmp(N, x);
            A = tmp;
        }
        if(query == 2){
            i64 i, x;
            cin >> i >> x;
            i--;
            A.at(i) += x;
        }
        if(query == 3){
            i64 i;
            cin >> i;
            i--;
            cout << A.at(i) << '\n';
        }
    }
}