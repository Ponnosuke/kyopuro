#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string ans = "";
    for(int i = 0; i < N; i++){
        char now = S.at(i);
        if(i < N-1){
            if(now == 'n' && S.at(i+1) == 'a'){
                ans += "nya";
                i++;
            }
            else{
                ans += now;
            }
        }
        else{
            ans += S.at(i);
        }
    }

    cout << ans << '\n';
}