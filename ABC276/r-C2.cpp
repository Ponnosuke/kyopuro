#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(auto &x : P)  cin >> x;

    prev_permutation(P.begin(), P.end());

    for(int i = 0; i < N; i++){
        cout << P.at(i);
        if(i < N-1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}