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
    int Q;
    cin >> Q;

    deque<pair<i64, i64>> dq;  // num, cnt
    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            i64 x, c;
            cin >> x >> c;
            dq.emplace_back(x, c);
        }
        if(type == 2){
            i64 c;
            cin >> c;

            i64 ret = 0;
            while(c > 0){
                auto[num, cnt] = dq.front();

                i64 subCnt = min(c, cnt);
                ret += num * subCnt;
                c -= subCnt;
                cnt -= subCnt;

                dq.pop_front();
                if(cnt > 0){
                    dq.emplace_front(num, cnt);
                }
            }

            cout << ret << '\n';
        }
    }

    return 0;
}