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
    i64 N, X;
    cin >> N >> X;
    vector<i64> P(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> P.at(i);
    }

    i64 nume = 0, deno = 100*100;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i + j == X){
                nume += P.at(i)*P.at(j);
            }
        }
    }

    debugV(nume);
    debugVL(deno);

    cout << fixed << setprecision(15);
    cout << (double)nume / (double)deno << endl;
}