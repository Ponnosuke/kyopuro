#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<i64> A(N);
    for(int i = 0; i < N; i++)  cin >> A.at(i);
    vector<i64> L(Q), R(Q), V(Q);
    for(int i = 0; i < Q; i++){
        i64 tmpL, tmpR, tmpV;
        cin >> tmpL >> tmpR >> tmpV;
        tmpL--;
        tmpR--;
        L.at(i) = tmpL;
        R.at(i) = tmpR;
        V.at(i) = tmpV;
    }

    vector<i64> diff(N-1, 0);
    for(int i = 0; i < N-1; i++){
        diff.at(i) = A.at(i+1) - A.at(i);
    }

    i64 ic = 0;
    for(int i = 0; i < N-1; i++){
        ic += abs(diff.at(i));
    }

    for(int i = 0; i < Q; i++){
        if(L.at(i) > 0){
            ic += abs(diff.at(L.at(i)-1) + V.at(i)) - abs(diff.at(L.at(i)-1));
            diff.at(L.at(i)-1) += V.at(i);
        }

        if(R.at(i) < N-1){
            ic += abs(diff.at(R.at(i)) - V.at(i)) - abs(diff.at(R.at(i)));
            diff.at(R.at(i)) -= V.at(i);
        }

        cout << ic << '\n';
    }
}