#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> P(N+1);
    for(int i = 2; i <= N; i++){
        cin >> P.at(i);
    }

    int index = N, ans = 0;
    while(true){
        ans++;
        if(P.at(index) <= 1){
            break;
        }
        index = P.at(index);
    }

    cout << ans << endl;
}