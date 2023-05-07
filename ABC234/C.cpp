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
    i64 K;
    cin >> K;

    stack<char> st;
    while(K > 0){
        if(K % 2 == 1){
            st.emplace('2');
        }
        else{
            st.emplace('0');
        }

        K /= 2;
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}