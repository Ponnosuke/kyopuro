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
    i64 N;
    cin >> N;

    string revS = S;
    reverse(revS.begin(), revS.end());
    int lenS = S.size();

    i64 maxNum = 0, add = 1, minNum = 0;

    for(int i = 0; i < lenS; i++){
        char nowCh = revS.at(i);
        // debugVL(nowCh);

        if(nowCh != '0'){
            maxNum += add;
            // debugV(add);
            // debugVL(maxNum);
        }

        if(nowCh == '1'){
            minNum += add;
        }

        add *= 2;
    }

    debugVL(maxNum);
    debugVL(minNum);

    if(minNum > N){
        cout << -1 << '\n';

        return 0;
    }

    if(N >= maxNum){
        cout << maxNum << '\n';

        return 0;
    }

    i64 ans = minNum;
    add = (1LL << (lenS - 1));
    for(int i = 0; i < lenS; i++){
        if(S.at(i) == '?'){
            debugVL(add);
            debugVL(ans);
            if(ans + add <= N){
                ans += add;
            }
        }
        add /= 2;
    }

    cout << ans << '\n';

    return 0;
}