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
    i64 N, K;
    cin >> N >> K;
    vector<string> S(N);
    vector<vector<bool>> isExisted(N, vector<bool>(26, false));
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
        for(int j = 0; j < S.at(i).size(); j++){
            int now = S.at(i).at(j) - 'a';
            isExisted.at(i).at(now) = true;
        }
    }

    i64 ans = 0;
    for(int i = 0; i < (1 << N); i++){
        vector<i64> alpCnt(26, 0);
        for(int j = 0; j < N; j++){
            if((i >> j) & 1){
                for(int k = 0; k < 26; k++){
                    if(isExisted.at(j).at(k)){
                        alpCnt.at(k)++;
                    }
                }
            }
        }

        i64 cnt = 0;
        for(auto ele : alpCnt){
            if(ele == K){
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
}