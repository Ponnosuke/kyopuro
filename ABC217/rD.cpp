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
    i64 L, Q;
    cin >> L >> Q;

    set<i64> st;
    st.insert(0);
    st.insert(L);
    while(Q--){
        i64 c, x;
        cin >> c >> x;

        if(c == 1){
            st.insert(x);
        }
        if(c == 2){
            auto itr = st.lower_bound(x);
            i64 R = *itr, L = *prev(itr);
            cout << R - L << '\n';
        }
    }

    return 0;
}