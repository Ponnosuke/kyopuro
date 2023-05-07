#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    int iniIndex = 0;

    for(int i = 0; i < Q; i++){
        int que, x;
        cin >> que >> x;

        if(que == 1){
            iniIndex = (iniIndex + N - x) % N;
        }

        if(que == 2){
            int index = ( iniIndex + (x - 1) ) % N;

            cout << S.at(index) << endl;
        }
    }
}