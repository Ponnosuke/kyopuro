#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, Q;
    cin >> N >> Q;
    vector<int> T(Q);
    vector<i64> A(Q), B(Q);
    for(int i = 0; i < Q; i++){
        cin >> T.at(i) >> A.at(i) >> B.at(i);
    }

    map<i64, set<i64>> mp;
    for(int i = 0; i < Q; i++){
        if(T.at(i) == 1){
            mp[A.at(i)].insert(B.at(i));

            continue;
        }

        if(T.at(i) == 2){
            if(mp[A.at(i)].count(B.at(i))){
                mp[A.at(i)].erase(B.at(i));
            }
        }

        if(T.at(i) == 3){
            if(mp[A.at(i)].count(B.at(i)) && mp[B.at(i)].count(A.at(i))){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }
        }
    }
}