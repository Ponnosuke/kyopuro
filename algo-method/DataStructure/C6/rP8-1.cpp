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
    vector<bitset<1000>> isFollower(N, bitset<1000>(0));
    
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int x, y;
            cin >> x >> y;

            isFollower.at(y).set(x, 1);
        }
        if(type == 1){
            int x, y;
            cin >> x >> y;

            isFollower.at(y).set(x, 0);
        }
        if(type == 2){
            int z;
            cin >> z;

            int cnt = 0;
            for(int i = 0; i < N; i++){
                if(i == z){
                    continue;
                }

                if(isFollower.at(z) == isFollower.at(i)){
                    cnt++;
                }
            }

            cout << cnt << '\n';
        }
    }
}