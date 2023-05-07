#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
using mint = atcoder::modint998244353;

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
    int Q;
    cin >> Q;

    deque<int> dq;
    dq.push_back(1);
    mint times = mint::raw(1);
    mint now = mint::raw(1);
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            int x;
            cin >> x;

            dq.push_back(x);
            now *= 10;
            now += x;
            times *= 10;
        }
        if(type == 2){
            int v = dq.front();
            now -= (v*times);
            dq.pop_front();
            times /= 10;
        }
        if(type == 3){
            cout << now.val() << '\n';
        }
    }
}