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
    i64 N, M, D;
    cin >> N >> M >> D;
    vector<i64> A(N), B(M);
    for(int i = 0; i < N; i++)  cin >> A.at(i);
    for(int i = 0; i < M; i++)  cin >> B.at(i);

    sort(B.begin(), B.end());
    i64 ans = -1;
    for(int i = 0; i < N; i++){
        auto itr = upper_bound(B.begin(), B.end(), A.at(i) + D);
        if(itr != B.begin()){
            int idx = distance(B.begin(), itr) - 1;
            if(B.at(idx) >= A.at(i) - D){
                ans = max(ans, A.at(i) + B.at(idx));
            }
        }
    }

    cout << ans << endl;

    return 0;
}