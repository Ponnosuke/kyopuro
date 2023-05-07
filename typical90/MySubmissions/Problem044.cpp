#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    vector<int> T(Q), x(Q), y(Q);
    for(int i = 0; i < Q; i++){
        int tmpT, tmpX, tmpY;
        cin >> tmpT >> tmpX >> tmpY;
        tmpX--;
        tmpY--;
        T.at(i) = tmpT;
        x.at(i) = tmpX;
        y.at(i) = tmpY;
    }

    int cnt = 0;
    for(int i = 0; i < Q; i++){
        if(T.at(i) == 1){
            int xpos = ((x.at(i) - cnt) % N + N) % N;
            int ypos = ((y.at(i) - cnt) % N + N) % N;
            swap(A.at(xpos), A.at(ypos));
        }

        if(T.at(i) == 2){
            cnt++;
        }

        if(T.at(i) == 3){
            int pos = ((x.at(i) - cnt) % N + N) % N;
            cout << A.at(pos) << '\n';
        }
    }

    return 0;
}