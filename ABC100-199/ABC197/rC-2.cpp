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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    if(N == 1){
        cout << A.at(0) << endl;

        return 0;
    }

    int Aor = 0, Axor = 0;
    int ans = INF;
    for(int i = 0; i < (1 << N); i++){
        if(!((i >> (N-1)) & 1)){
            continue;
        }

        Aor = 0;
        Axor = 0;

        for(int j = 0; j < N; j++){
            Aor |= A.at(j);
            if((i >> j) & 1){
                Axor ^= Aor;
                Aor = 0;
            }
        }

        ans = min(ans, Axor);
    }

    cout << ans << endl;

    return 0;
}