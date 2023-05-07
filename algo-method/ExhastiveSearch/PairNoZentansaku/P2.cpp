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
    int L, R;
    cin >> L >> R;
    
    int ans = 0;
    for(int i = L; i <= R; i++){
        for(int j = i+1; j <= R; j++){
            int degi = i % 10, degj = j % 10;
            if(degi == degj){
                ans++;
            }
        }
    }

    cout << ans << endl;
}