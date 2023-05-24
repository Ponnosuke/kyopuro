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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> T.at(i);

        sum += T.at(i);
    }

    set<int> st;
    st.insert(0);
    for(int i = 0 ; i < N; i++){
        set<int> pt = st;
        for(int x : st){
            pt.insert(x + T.at(i));
        }

        swap(st, pt);
    }

    int ans = INF;
    for(int x : st){

        debugVL(x);

        ans = min(ans, max(x, sum - x));
    }

    cout << ans << '\n';

    return 0;
}