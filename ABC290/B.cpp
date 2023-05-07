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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int cnt = 0;
    string ans = "";
    for(int i = 0; i < S.size(); i++){
        if(cnt >= K){
            ans += 'x';
            continue;
        }

        if(S.at(i) == 'o'){
            if(cnt < K){
                ans += 'o';
                cnt++;
            }
            else{
                ans += 'x';
            }
        }
        else{
            ans += 'x';
        }

    }

    cout << ans << endl;
}