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
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vector<double> X(5*N, 0);
    for(int i = 0; i < 5*N; i++){
        cin >> X.at(i);
    }

    sort(X.begin(), X.end());
    double sum = 0;
    for(int i = N; i < 4*N; i++){
        sum += X.at(i);
    }

    double dN = N;

    cout << sum/(3*dN) << endl;
}