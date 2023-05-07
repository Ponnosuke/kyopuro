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
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    if(N == 1){
        cout << A.at(0) << endl;

        return 0;
    }

    i64 Aor = 0, Axor = 0;
    i64 ans = INF;
    for(int i = 0; i < (1 << N-1); i++){
        Aor = 0;
        Axor = 0;

        for(int j = 0; j < N-1; j++){
            Aor |= A.at(j);
            if((i >> j) & 1){
                Axor ^= Aor;
                Aor = 0;
            }
        }

        Aor |= A.at(N-1);
        Axor ^= Aor;

        ans = min(ans, Axor);
    }

    cout << ans << endl;

    return 0;
}