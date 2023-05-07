#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &x : A)  cin >> x;

    for(int i = 0; i < K; i++){
        for(int j = 0; j < N-1; j++){
            A[j] = A[j+1];
        }
        A[N-1] = 0;
    }

    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i < N-1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}