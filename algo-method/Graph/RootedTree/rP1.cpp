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
    int N, X;
    cin >> N >> X;
    vector<int> A(N, 0);
    for(int i = 1; i <= N-1; i++)  cin >> A[i];

    int ans = 1, v = X;
    while(v != 0){
        v = A[v];

        if(v == 0){
            break;
        }

        ans++;
    }

    cout << ans << endl;
}