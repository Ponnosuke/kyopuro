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
    int N, L;
    cin >> N >> L;
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    queue<i64> Q;
    i64 total = 0;
    i64 cnt = 0;
    vector<i64> num(N, 0);
    for(int i = 0; i < N; i++){
        num.at(i) = max(A.at(i) - total, (i64)0);
        Q.push(num.at(i));
        total += num.at(i);

        if(Q.size() >= L){
            total -= Q.front();
            Q.pop();
        }
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        ans += num.at(i);
    }

    cout << ans << endl;
}