/*
    C - Make Takahashi Happy https://atcoder.jp/contests/abc293/tasks/abc293_c 

    next_permutation() を使って全探索する方法

    実行時間だけ見ると dfs の方法よりは重く、bit全探索の方法よりは軽いっぽい。計算量的にはどうなんだろ
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }

    int M = (H-1) + (W-1);
    vector<int> flag(M, 0);
    for(int i = W-1; i < M; i++){
        flag.at(i) = 1;
    }

    int ans = 0;
    do{
        int x = 0, y = 0;
        bool OK = true;
        set<int> st;
        st.insert(A.at(0).at(0));
        for(int i = 0; i < M; i++){
            if(flag.at(i) == 0){
                x++;
            }
            else{
                y++;
            }

            if(st.count(A.at(y).at(x))){
                OK = false;
                break;
            }
            else{
                st.insert(A.at(y).at(x));
            }
        }

        if(OK){
            ans++;
        }

    }while(next_permutation(flag.begin(), flag.end()));

    cout << ans << endl;
}