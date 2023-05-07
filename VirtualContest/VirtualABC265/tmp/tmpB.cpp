#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, M, T;
    cin >> N >> M >> T;
    vector<i64> A(N);
    for(int i = 1; i <= N-1; i++)  cin >> A.at(i);
    vector<i64> X(M+1), Y(M+1);
    for(int i = 1; i <= M; i++) cin >> X.at(i) >> Y.at(i);

    bool OK = true;
    int index = 1;
    for(int i = 1; i <= N-1; i++){

        // debug
        // cout << i << endl;

        if(index <= M){
            if(i == X.at(index)){
                T += Y.at(index);
                index++;

                // debug
                // cout << "routeA" << endl;
            }
        }

        T -= A.at(i);

        // debug
        // cout << i << endl;

        if(T <= 0){
            OK = false;

            // debug
            // cout << "routeB" << endl;

            break;
        }

        // debug
        // cout << i << endl;
    }

    cout << (OK ? "Yes" : "No") << endl;
}