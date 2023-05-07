#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    for(int i = 0; i < Q ; i++){
        int qL, qR;
        cin >> qL >> qR;

        if(qL == 1){
            S = S.substr(N - qR, qR) + S.substr(0, N - qR);
        }
        else{
            cout << S.at(qR - 1) << endl;
        }
    }
}