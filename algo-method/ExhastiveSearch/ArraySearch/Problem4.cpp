#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> A(N);
    for(auto &x : A)  cin >> x;

    int ans = -1;
    for(int i = 0; i < N; i++){
        if(A.at(i) == V)  ans = i;
    }

    cout << ans << endl;
}