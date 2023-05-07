#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<i64> L(N+1);
    L.at(0) = 2;
    L.at(1) = 1;

    for(int i = 2; i <= N; i++){
        L.at(i) = L.at(i-1) + L.at(i-2);
    }

    cout << L.at(N) << endl;
}