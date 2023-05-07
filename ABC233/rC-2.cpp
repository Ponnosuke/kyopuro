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
    i64 N, X;
    cin >> N >> X;
    vector<vector<i64>> a(N);
    for(i64 i = 0; i < N; i++){
        i64 L;
        cin >> L;
        for(i64 j = 0; j < L; j++){
            i64 ia;
            cin >> ia;
            a.at(i).push_back(ia);
        }
    }

    vector<i64> S1 = {1}, S2;
    for(int i = 0; i < N; i++){
        S2.clear();
        for(i64 ele1 : S1){
            for(i64 ele2 : a.at(i)){
                if(ele1 > X/ele2){
                    continue;
                }

                S2.push_back(ele1 * ele2);
            }
        }

        // debug
        // debugVL(i);
        // debugWL(S1);
        // for(i64 ele1 : S1){
        //     debug(ele1);
        // }
        // debugWL();
        // debugWL(S2);
        // for(i64 ele2 : S2){
        //     debug(ele2);
        // }
        // debugWL();
        
        S1 = S2;
    }

    i64 ans = 0;
    for(i64 ele : S1){

        debugVL(ele);

        if(ele == X){
            ans++;
        }
    }
    cout << ans << '\n';
}