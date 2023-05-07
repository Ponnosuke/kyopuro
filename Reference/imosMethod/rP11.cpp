/*
    Q11. シール貼り | アルゴ式 https://algo-method.com/tasks/891 

    imos法を使った解法
*/

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
    vector<i64> table(N+L+1, 0);
    for(int i = 0; i < N; i++){
        i64 add = max((i64)A.at(i) - table.at(i), (i64)0);
        cnt += add;

        table.at(i) += add;
        table.at(i+L) -= add;

        table.at(i+1) += table.at(i);
    }

    cout << cnt << '\n';
}