#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<bool>> follow(N, vector<bool>(N, false));  // follow[i][j] := i が j を フォローしているか
    while(Q--){
        int type;
        cin >> type;
        if(type == 0){
            int x, y;
            cin >> x >> y;
            follow.at(x).at(y) = true;
        }
        else{
            int z;
            cin >> z;

            bool exist = false;
            for(int i = 0; i < N; i++){
                if(i == z){
                    continue;
                }

                if(follow.at(i).at(z)){
                    cout << i << " ";
                    exist = true;
                }
            }

            if(!exist){
                cout << "No";
            }
            cout << '\n';
        }
    }
}