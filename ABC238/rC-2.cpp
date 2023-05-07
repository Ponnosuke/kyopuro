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
    ui64 N;
    cin >> N;

    mint ans = 0;

    ui64 num = 9;
    ui64 preNum = 9;
    mint cnt = 9;

    i64 timeCnt = 0;
    
    while(N >= num){
        mint add = 1 + cnt;
        add *= cnt;
        add /= 2;

        ans += add;
        cnt *= 10;

        preNum = num;

        if(timeCnt < 18){
            num *= 10;
            num += 9;
            timeCnt++;
        }
    }

    num = preNum;

    i64 ele = (N - num);
    mint add = (1 + ele);
    add *= ele;
    add /= 2;
    ans += add;

    cout << ans.val() << '\n';
}