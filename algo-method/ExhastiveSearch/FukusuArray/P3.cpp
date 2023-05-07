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
    int X, Y, Z;
    cin >> X >> Y >> Z;
    vector<int> A(X), B(Y), C(Z);
    for(auto &x : A)  cin >> x;
    for(auto &x : B)  cin >> x;
    for(auto &x : C)  cin >> x;

    int ans = 0;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            for(int k = 0; k < Z; k++){
                if(A.at(i) + B.at(j) == C.at(k)){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}