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
    int N, Q;
    cin >> N >> Q;
    vector<vector<bool>> isfollower(N, vector<bool>(N, false));
    // [i][j] := i のフォロワー情報、j はフォロワーか否か
    map<vector<bool>, int> mp;
    for(int i = 0; i < N; i++){
        mp[isfollower.at(i)]++;
    }

    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int x, y;
            cin >> x >> y;
            mp[isfollower.at(y)]--;
            isfollower.at(y).at(x) = true;
            mp[isfollower.at(y)]++;
        }
        if(type == 1){
            int x, y;
            cin >> x >> y;
            mp[isfollower.at(y)]--;
            isfollower.at(y).at(x) = false;
            mp[isfollower.at(y)]++;
        }
        if(type == 2){
            int z;
            cin >> z;

            cout << mp[isfollower.at(z)] - 1 << '\n';
        }
    }
}