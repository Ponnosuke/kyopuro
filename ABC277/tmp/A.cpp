#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> P(N);
    for(int i = 0; i < N; i++)  cin >> P.at(i);

    int ans = -1;
    for(int i = 1; i <= N; i++){
        if(P.at(i-1) == X){
            ans = i;
        }
    }

    cout << ans << endl;
}