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

    deque<i64> dq;
    dq.push_back(1);

    mint now = 1;
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            i64 x;
            cin >> x;

            dq.push_back(x);

            now *= 10;
            now += x;
        }
        if(type == 2){
            mint sub = dq.front();
            dq.pop_front();
            mint num = mint::raw(10);
            mint times = num.pow((int)dq.size());
            sub *= times;

            now = now - sub;
        }
        if(type == 3){
            cout << now.val() << '\n';
        }
    }

    return 0;  
}