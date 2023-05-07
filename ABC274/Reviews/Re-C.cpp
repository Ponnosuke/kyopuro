#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1, -1);
    for(int i = 1; i <= N; i++){
        cin >> A.at(i);
    }

    vector<int> ans(2*N + 2, -1);
    ans.at(1) = 0;
    for(int i = 1; i <= N; i++){
        ans.at(2*i) = ans.at(A.at(i)) + 1;
        ans.at(2*i + 1) = ans.at(A.at(i)) + 1;
    }

    for(int i = 1; i <= 2*N + 1; i++){
        cout << ans.at(i) << '\n';
    }

    return 0;
}