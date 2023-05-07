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
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    i64 cnt = 0;
    vector<i64> table(N+1, 0);
    for(int i = 0; i < N; i++){
        i64 tmp = 0;
        while(A.at(i) > tmp + table.at(i)){
            tmp++;
        }

        table.at(i) += tmp;
        if(i+L < N){
            table.at(i+L) -= tmp;
        }

        table.at(i+1) += table.at(i);
        cnt += tmp;
    }

    cout << cnt << '\n';
}