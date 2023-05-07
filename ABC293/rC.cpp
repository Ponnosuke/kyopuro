/*
    C - Make Takahashi Happy https://atcoder.jp/contests/abc293/tasks/abc293_c 
    bitset を使ったやりかた
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
    vector<vector<int>> A(H, vector<int>(W, 0));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }

    int M = (H-1) + (W-1);
    int ans = 0;
    for(int i = 0; i < (1 << M); i++){
        bitset<18> bs(i);
        if(bs.count() != H-1){
            continue;
        }

        debugVL(bs);

        int x = 0, y = 0;
        set<int> st;
        st.insert(A.at(0).at(0));
        bool OK = true;

        for(int j = 0; j < M; j++){
            if(bs.test(j)){
                y++;
            }
            else{
                x++;
            }

            if(st.count(A.at(y).at(x))){
                debugVL(A.at(y).at(x));
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