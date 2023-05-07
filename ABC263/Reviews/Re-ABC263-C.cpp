#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> C(M, 0);
    for(int i = N; i <= M - 1; i++) C.at(i) = 1;

    // C配列 ソート済み

    // debug
    // cout << "A" << endl;

    do{
        for(int i = 0; i < M; i++){
            if(C.at(i) == 0){
                cout << i+1;
                if(i < M-1){
                    cout << " ";
                }
            }

            // debug
            /*
            cout << C.at(i);
            if(i < M-1){
                cout << " ";
            }
            else{
                cout << endl;
            }
            */
            // 辞書順に小さい順に0, 1出力
        }

        cout << endl;
    } while (next_permutation(C.begin(), C.end()));

    // debug
    // cout << "B" << endl;

    return 0;
}