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
    int N, K;
    cin >> N >> K;
    vector<int> P(N, 0);
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }

    set<int> st;
    for(int i = 0; i < N; i++){
        st.insert(P.at(i));

        if(i+1 >= K){
            cout << *prev(st.end(), K) << '\n';
            // O(K) かかる
        }
    }

    return 0;
}