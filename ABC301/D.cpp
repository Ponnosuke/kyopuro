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

    vector<i64> cor;
    // add = (1LL << lenS);
    // add /= 2;
    // debugVL(add);
    // bitset<60> bS(N);

    // debugVL(lenS);

    cor.push_back(0);

    add = 1;
    for(int i = 0; i < lenS; i++){
        i64 cSize = cor.size();
        char nowCh = revS.at(i);
        if(nowCh != '0'){
            for(int j = 0; j < cSize; j++){
                i64 num = cor.at(j);
                cor.push_back(num + add);
            }
        }

        add *= 2;
    }

    sort(cor.begin(), cor.end());

    // debug
    debugWL(cor);
    for(i64 ele : cor){
        debug(ele);
    }
    debugWL();

    debugVL(N);
    i64 ans = *prev(upper_bound(cor.begin(), cor.end(), N));

    cout << ans << '\n';

    return 0;
}