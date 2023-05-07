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
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i);
    }

    double ans = -1;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            ans = max(ans, hypot(x.at(i) - x.at(j), y.at(i) - y.at(j)));
        }
    }

    cout << fixed << setprecision(20);
    cout << ans << endl;
}