#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

int main() {
    string S;
    cin >> S;
    i64 ans = 0;
    i64 Ssize = S.size();
    for(int i = 0; i < Ssize; i++){
        if(i < Ssize - 1){

            debugP(routeA);

            if(S.at(i) == '0'){
                if(S.at(i+1) == '0'){
                    ans++;
                    i++;
                }
                else{
                    ans++;
                }
            }
            else{
                ans++;
            }
        }
        else{

            debugP(routeB);

            ans++;
        }
    }
    cout << ans << '\n';
}