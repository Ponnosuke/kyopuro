#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    cin.tie(nullptr);

    ios::sync_with_stdio(false);  
    // C++ の標準入出ストリームが C の入出力と同期しないようにする
    // std::cin と scanf(), std::cout と printf() を混ぜると破滅することに注意
    // これを使ったら、Line: 37 からの forループで全部の入力を待ってから出力できるようになった
    // これがないと、L R の入力一回ごとに結果が出力されてコンソールがごっちゃごっちゃになる

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

        // debug
        // cout << "S1.at(" << i << ") = " << S1.at(i) << ",  " << "S2.at(" << i << ") = " << S2.at(i) << "\n";
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int L, R;
        cin >> L >> R;

        cout << S1.at(R) - S1.at(L-1) << " " << S2.at(R) - S2.at(L-1) << "\n";
    }

    return 0;
}