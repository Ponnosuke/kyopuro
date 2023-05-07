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
    i64 N;
    cin >> N;
    vector<i64> T(N), K(N);
    vector<vector<i64>> G(N);
    for(int i = 0; i < N; i++){
        i64 iT, iK;
        cin >> iT >> iK;
        T.at(i) = iT;
        K.at(i) = iK;

        for(int j = 0; j < iK; j++){
            i64 A;
            cin >> A;
            A--;
            G.at(i).push_back(A);
        }
    }

    vector<bool> seen(N, false);
    seen.at(N-1) = true;
    queue<i64> Q;
    Q.push(N-1);
    i64 ans = 0;
    while(!Q.empty()){
        i64 v = Q.front();
        Q.pop();
        ans += T.at(v);

        for(i64 nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }
            seen.at(nv) = true;

            Q.push(nv);
        }
    }

    cout << ans << endl;
}