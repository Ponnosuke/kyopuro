#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    set<i64> S;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        S.insert(a);
    }

    i64 vol = 1;
    while(N > 0){
        if(S.count(vol)){
            N--;
            vol++;
        }
        else{
            if(N >= 2){
                N -= 2;
                vol++;
            }
            else{
                break;
            }
        }
    }

    vol--;

    cout << vol << endl;
}