#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<int> cnt(10, 0);

    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        
        cnt.at(A)++;
    }

    int ans = 1, maxCnt = cnt.at(1);
    for(int i = 2; i <= 9 ; i++){
        if(maxCnt < cnt.at(i)){
            maxCnt = cnt.at(i);
            ans = i;
        }        
    }

    cout << ans << endl;
}