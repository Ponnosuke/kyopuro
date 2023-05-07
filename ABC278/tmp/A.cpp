#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    if(N <= K){
        for(int i = 0; i < N; i++){
            cout << 0;
            if(i < N-1){
                cout << " ";
            }
            else{
                cout << '\n';
            }
        }

        return 0;
    }

    for(int i = K; i < N; i++){
        cout << A.at(i) << " ";
    }
    for(int i = 0; i < K; i++){
        cout << 0;
        if(i < K-1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }

    return 0;
}