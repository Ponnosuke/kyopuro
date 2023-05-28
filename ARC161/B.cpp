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

const ui64 UPPER = (1LL << 60);

int main() {
    int T;
    cin >> T;

    while(T--){
        ui64 N;
        cin >> N;

        bitset<70UL> bs(N);
        if(bs.count() == 3){
            cout << N << '\n';

            continue;
        }
        
        debugVL(N);

        int cnt = 0;
        ui64 now = 0;
        ui64 add = UPPER;
        for(int rep = 0; rep <= 60; rep++){
            if((now + add) < N){
                now += add;
                cnt++;
            }

            debugVL(now);
            debugVL(cnt);
            debugVL(add);
            debugWL();

            add /= 2;
            if(cnt >= 3){
                break;
            }
        }

        if(cnt == 3){
            cout << now << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}