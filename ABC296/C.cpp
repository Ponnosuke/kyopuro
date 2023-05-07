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
    i64 N, X;
    cin >> N >> X;
    vector<i64> A(N, 0);
    set<i64> st;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        st.insert(A.at(i));
    }

    // sort(A.begin(), A.end());

    // debug
    // for(int i = 0; i < N; i++){
    //     debug(A.at(i));
    // }
    // debugWL();

    bool OK = false;
    for(int i = 0; i < N; i++){
        if(st.count(A.at(i) + X)){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}