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

const i64 INF = (1LL << 60);

int main() {
    i64 A, B, R, S;
    cin >> A >> B >> R >> S;

    i64 G = gcd(A-R, B-S);
    i64 th = max(R, S);
    if(G < th){
        cout << -1 << endl;

        return 0;
    }

    debugVL(G);

    vector<i64> divs;
    for(i64 i = 1; i*i <= G; i++){
        if(G % i != 0){
            continue;
        }
        
        divs.push_back(i);
        if(G/i != i){
            divs.push_back(G/i);
        }
    }

    i64 ans = G, vecSize = divs.size();
    for(int i = 0; i < vecSize; i++){
        debugVL(i);
        debugVL(divs.at(i));

        i64 now = divs.at(i);
        if(th < now){
            ans = min(ans, now);
        }
        debugWL();
    }

    cout << ans << endl;
}