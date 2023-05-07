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
    int N;
    cin >> N;
    vector<double> P(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> P.at(i);
    }

    double ans = 1;
    for(int i = 1; i <= N; i++){
        double tmp = min(P.at(i)/100.0, (1.0 - P.at(i))/100.0);
        if(tmp == )
    }

    cout << fixed << setprecision(18);
    cout << ans << '\n';
}