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
    int N, M;
    cin >> N >> M;

    double p1 = 1.0, p2 = 1.0;  // p1 - p2
    for(int i = 0; i < N; i++){
        p1 *= (double)M / 6.0;
        p2 *= (double)(M-1) / 6.0;
    }

    cout << fixed << setprecision(19);
    cout << p1 - p2 << endl;

    return 0;
}