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
    string S;
    cin >> S;

    set<char> st;
    for(int i = 0; i < S.size(); i++){
        st.insert(S.at(i));
    }

    string ans = "None";
    for(char ch = 'a'; ch <= 'z'; ch++){
        debugVL(ch);
        if(!st.count(ch)){
            ans = ch;
            break;
        }
    }

    cout << ans << endl;
}