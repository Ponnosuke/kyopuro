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
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    stack<int> st;
    st.push(0);
    vector<int> ans(N, 0);
    for(int i = 1; i < N; i++){
        while(A.at(st.top()) >= A.at(i)){
            st.pop();
        }

        ans.at(i) = i - st.top();

        debugV(i);
        debugVL(st.top());

        st.push(i);

    }

    for(int i = 1; i < N; i++){
        cout << ans.at(i);
        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}