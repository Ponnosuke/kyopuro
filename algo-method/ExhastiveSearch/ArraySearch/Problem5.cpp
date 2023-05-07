#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &x : A)  cin >> x;

    int ans = 0;
    for(int i = 1; i < N; i++){
        if(A.at(i) > A.at(i - 1))  ans++;
    }

    cout << ans << endl;
}