#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    int Q;
    cin >> Q;

    vector<vector<bool>> follow(N, vector<bool>(N, false));  // follow[i][j] := i が j をフォローしているか
    vector<int> follower(N, 0);  // follower[i] := i のフォロワー数
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int x, y;
            cin >> x >> y;

            if(!follow.at(x).at(y)){
                follow.at(x).at(y) = true;
                follower.at(y)++;
            }
        }
        if(type == 1){
            int x, y;
            cin >> x >> y;

            if(follow.at(x).at(y)){
                follow.at(x).at(y) = false;
                follower.at(y)--;
            }
        }
        if(type == 2){
            int z;
            cin >> z;

            cout << follower.at(z) << '\n';
        }
    }
}