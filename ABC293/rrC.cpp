/*
    C - Make Takahashi Happy https://atcoder.jp/contests/abc293/tasks/abc293_c 

    bitset を使わずに GCC 処理系で bit全探索での解答
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

    int ans = 0;
    int M = (H-1) + (W-1);
    for(int i = 0; i < (1 << M); i++){
        if(__builtin_popcount(i) != H-1){
            continue;
        }

        // 1 -> H, 0 -> W
        bool OK = true;
        set<int> st;
        int x = 0, y = 0;
        st.insert(A.at(0).at(0));
        for(int j = 0; j < M; j++){
            if((i >> j) & 1){
                y++;
            }
            else{
                x++;
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
    }

    cout << ans << endl;
}