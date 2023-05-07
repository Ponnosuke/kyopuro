#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, K, D;
    cin >> N >> K >> D;
    vector<i64> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    map<i64, i64> facts;
    i64 tmpD = D;
    for(i64 i = 2; i*i <= tmpD; i++){
        if(tmpD % i != 0){
            continue;
        }

        i64 cnt = 0;
        while(tmpD % i == 0){
            cnt++;
            tmpD /= i;
        }

        facts[i] = cnt;
    }
    if(tmpD > 1){
        facts[tmpD] = 1;
    }

    
}