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
    int N, A, B;
    cin >> N >> A >> B;
    vector<string> S(N);
    for(int i = 0; i < N; i++)  cin >> S.at(i);

    bool OK = false;
    if(S.at(A).at(B) == 'o'){
        OK = true;
    }

    cout << (OK ? "Yes" : "No") << '\n';
}