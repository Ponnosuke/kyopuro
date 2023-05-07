#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<int> ans(10, 0);

    for(int i = 0; i < N; i++){
        int A;
        cin >> A;

        ans.at(A)++;
    }

    for(int i = 1; i <= 9; i++){
        cout << ans.at(i) << endl;
    }
}