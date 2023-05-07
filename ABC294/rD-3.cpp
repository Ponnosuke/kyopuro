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
    int N, Q;
    cin >> N >> Q;

    vector<bool> gone(N+1, false);
    int ans = 1;
    while(Q--){
        int type;
        cin >> type;

        if(type == 2){
            int x;
            cin >> x;

            gone.at(x) = true;
        }
        if(type == 3){
            while(gone.at(ans)){
                ans++;
            }

            cout << ans << '\n';
        }
    }
}