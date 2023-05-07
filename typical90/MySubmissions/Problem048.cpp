#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, K;
    cin >> N >> K;
    vector<i64> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    vector<i64> vec(2*N, 0);
    for(int i = 0; i < N; i++){
        vec.at(i) = B.at(i);
    }
    for(int i = 0; i < N; i++){
        vec.at(i + N) = A.at(i) - B.at(i);
    }
    sort(vec.begin(), vec.end(), greater<int>());

    i64 ans = 0;
    for(int i = 0; i < K; i++){
        ans += vec.at(i);
    }

    cout << ans << endl;
}