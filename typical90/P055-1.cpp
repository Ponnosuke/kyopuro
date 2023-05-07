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
    int N;
    cin >> N;
    i64 P, Q;
    cin >> P >> Q;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
 
    i64 ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                for(int l = k + 1; l < N; l++){
                    for(int m = l + 1; m < N; m++){
                        i64 tmp = 1;
                        
                        // vector<int> index = {i, j, k, l, m};
                        // for(int idx = 0; idx < 5; idx++){
                        //     tmp *= (A.at(index.at(idx)) % P);
                        //     tmp %= P;
                        // }
 
                        tmp *= (A.at(i) % P);
                        tmp *= (A.at(j) % P);
                        tmp %= P;
                        tmp *= (A.at(k) % P);
                        tmp %= P;
                        tmp *= (A.at(l) % P);
                        tmp %= P;
                        tmp *= (A.at(m) % P);
                        tmp %= P;
 
                        if((tmp % P) == Q){
                            ans++;
                        }
                    }
                }
            }
        }
    }
 
    cout << ans << endl;
}