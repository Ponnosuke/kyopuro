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
    int N;
    cin >> N;
    set<string> st;
    for(int i = 0; i < N; i++){
        string S = "";

        int L;
        cin >> L;
        for(int j = 0; j < L; j++){
            int num;
            cin >> num;
            S += (char)('0' + num);
        }

        st.insert(S);
    }

    cout << (int)st.size() << endl;
}