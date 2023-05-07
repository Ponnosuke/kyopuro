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
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = -1;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(S.at(i) == '-'){
            if(cnt != 0){
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        else{
            cnt++;
        }
    }

    cnt = 0;
    reverse(S.begin(), S.end());
    for(int i = 0; i < N; i++){
        if(S.at(i) == '-'){
            if(cnt != 0){
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        else{
            cnt++;
        }
    }

    cout << ans << endl;
}