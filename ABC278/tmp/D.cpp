#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    i64 N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    queue<int> indexQ;
    for(int i = 0; i < N; i++){
        indexQ.emplace(i);
        // indexQ.push(i);
    }
    i64 resetA = 0;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int query;
        cin >> query;

        if(query == 1){
            i64 x;
            cin >> x;
            resetA = x;
            while(!indexQ.empty()){
                A.at(indexQ.front()) = 0;
                indexQ.pop();
            }
        }
        if(query == 2){
            int i;
            i64 x;
            cin >> i >> x;
            i--;
            A.at(i) += x;

            indexQ.emplace(i);
        }
        if(query == 3){
            int i;
            cin >> i;
            i--;
            cout << A.at(i) + resetA << '\n';
        }
    }

    return 0;
}