#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int T;
    cin >> T;
    for(int rep = 0; rep < T; rep++){
        i64 N;
        cin >> N;

        i64 tmpN = N;

        pair<i64, i64> pp;
        for(i64 a = 2; a*a*a <= N; a++){
            i64 cnt = 0;
            while(N % a == 0){
                cnt++;
                N /= a;
            }

            pp = make_pair(a, cnt);
            if(cnt > 0){
                break;
            }
        }

        i64 p, q;
        debug(pp.first);
        debugL(pp.second);
        if(pp.second == 1){
            debugP(routeA);
            q = pp.first;
            p = sqrt(tmpN / q);
        }
        else{
            debugP(routeB);
            p = pp.first;
            q = tmpN / (p*p);
        }

        cout << p << " " << q << '\n';
    }
}