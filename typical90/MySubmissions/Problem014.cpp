#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        cin >> B.at(i);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // debug
    cerr << "debug" << '\n';
    for(auto x : A){
        cerr << x << " ";
    }
    cerr << '\n';
    for(auto x : B){
        cerr << x << " ";
    }
    cerr << '\n';

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        ans += abs(A.at(i) - B.at(i));
    }

    cout << ans << endl;
}