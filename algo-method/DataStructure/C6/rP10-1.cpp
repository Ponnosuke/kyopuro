/*
    Q10. 4 つの整数 (2)

    https://algo-method.com/submissions/974934

    unordered_set を用いる

    601 ms
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
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    unordered_set<i64> st;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            i64 num1 = A.at(i), num2 = A.at(j);
            st.insert(num1*num1 + num2*num2);
        }
    }

    bool OK = false;
    for(i64 x : st){
        if(st.count(M-x)){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}