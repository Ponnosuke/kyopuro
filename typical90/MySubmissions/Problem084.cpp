#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

i64 calSum(i64 n){
    return (n * (n + 1)) / 2;
}

int main() {
    i64 N;
    cin >> N;
    string S;
    cin >> S;

    if(N == 1){
        cout << 0 << endl;
        return 0;
    }

    i64 cnt = 1, sum = 0;
    for(i64 i = 0; i < N-1; i++){
        if(S.at(i) == S.at(i+1)){
            cnt++;
            if(i == N-2){
                sum += calSum(cnt);
            }
        }
        else{
            sum += calSum(cnt);
            cnt = 1;
            if(i == N-2){
                sum++;
            }
        }
    }

    i64 ans = calSum(N) - sum;
    cout << ans << endl;

    return 0;
}