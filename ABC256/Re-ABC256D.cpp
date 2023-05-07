#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    vector<pair<i64, i64>> LR(N);
    for(int i = 0; i < N; i++){
        i64 l, r;
        cin >> l >> r;
        LR.at(i) = make_pair(l, r);
    }

    sort(LR.begin(), LR.end());

    vector<i64> X, Y;  // Xが下、Yが上

    for(int i = 0; i < N; i++){
        i64 l = LR.at(i).first, r = LR.at(i).second;
        if(X.empty() || Y.back() < l){
            X.push_back(l);
            Y.push_back(r);
        }
        else{
            if(Y.back() < r){
                Y.back() = r;
            }
        }
    }

    for(int i = 0; i < X.size() ; i++){
        cout << X.at(i) << " " << Y.at(i) << endl;
    }


}
