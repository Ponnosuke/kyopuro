#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> S1(N+1, 0), S2(N+1, 0);
    for(int i = 0; i < N; i++){
        int c, p;
        cin >> c >> p;

        if(c == 1){
            S1.at(i+1) = S1.at(i) + p;
            S2.at(i+1) = S2.at(i);
        }
        else{
            S1.at(i+1) = S1.at(i);
            S2.at(i+1) = S2.at(i) + p;
        }
    }

    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    for(int i = 0; i < Q; i++){
        cin >> L.at(i) >> R.at(i);
    }

    for(int i = 0; i < Q; i++){
        int tmpL = L.at(i), tmpR = R.at(i);
        cout << S1.at(tmpR) - S1.at(tmpL-1) << " " << S2.at(tmpR) - S2.at(tmpL-1) << "\n";
    }

    return 0;
}