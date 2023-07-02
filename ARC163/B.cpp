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
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    i64 A1 = A.at(0), A2 = A.at(1);
    i64 cnt = 0;
    vector<i64> diff(N, INF);
    for(int i = 2; i < N; i++){
        i64 nowA = A.at(i);
        if(A1 <= nowA && nowA <= A2){
            diff.at(i) = INF;
            cnt++;
        }
        else if (nowA < A1){
            diff.at(i) = A1 - nowA;
        }
        else{  // A2 < nowA
            diff.at(i) = nowA - A2;
        }
    }

    // debug
    debugVL(cnt);
    for(int i = 0; i < N; i++){
        debugV(i);
        debugVL(diff.at(i));
    }
    debugWL();

    if(cnt >= M){
        cout << 0 << '\n';
    }
    else{
        i64 ans = 0;
        i64 rest = M - cnt;

        sort(diff.begin(), diff.end());

        for(int i = 0; i < rest; i++){
            ans += diff.at(i);
        }

        cout << ans << '\n';
    }

    return 0;
}