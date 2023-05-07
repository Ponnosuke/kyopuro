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
    i64 L, N1, N2;
    cin >> L >> N1 >> N2;

    queue<pair<i64, i64>> up, down;
    for(int i = 0; i < N1; i++){
        i64 iv, il;
        cin >> iv >> il;

        up.emplace(make_pair(iv, il));
    }
    for(int i = 0; i < N2; i++){
        i64 iv, il;
        cin >> iv >> il;

        down.emplace(make_pair(iv, il));
    }

    i64 ans = 0;
    pair<i64, i64> nowUp = up.front(), nowDown = down.front();
    up.pop();
    down.pop();
    while(true){
        i64 tmp = min(nowUp.second, nowDown.second);

        debugV(nowUp.first);
        debugVL(nowUp.second);
        debugV(nowDown.first);
        debugVL(nowDown.second);
        debugVL(tmp);

        nowUp.second -= tmp;
        nowDown.second -= tmp;



        if(nowUp.first == nowDown.first){
            ans += tmp;
        }

        if(nowUp.second == 0){
            if(up.empty()){
                break;
            }
            nowUp = up.front();
            up.pop();
        }
        if(nowDown.second == 0){
            if(down.empty()){
                break;
            }
            nowDown = down.front();
            down.pop();
        }

        debugWL();
    }

    cout << ans << '\n';
}