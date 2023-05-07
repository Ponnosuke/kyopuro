#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N, 0), B(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        cin >> B.at(i);
    }

    i64 sum = 0;
    for(int i = 0; i < N; i++){
        sum += abs(A.at(i) - B.at(i));
    }

    bool OK = false;
    if(sum <= K){
        if(sum % 2 == K % 2){
            OK = true;
        }
    }

    cout << (OK ? "Yes" : "No") << "\n";

    return 0;
}