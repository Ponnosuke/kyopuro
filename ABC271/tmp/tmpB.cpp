#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<i64>> A(N);
    for(int i = 0; i < N; i++){
        int L;
        cin >> L;
        for(int j = 0; j < L; j++){
            i64 tmpA;
            cin >> tmpA;
            A.at(i).push_back(tmpA);
        }
    }

    vector<i64> s(Q), t(Q);
    for(int i = 0; i < Q; i++){
        i64 tmpS, tmpQ;
        cin >> tmpS >> tmpQ;
        tmpS--;
        tmpQ--;

        cout << A.at(tmpS).at(tmpQ) << endl;
    }

}