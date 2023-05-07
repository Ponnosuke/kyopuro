#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3391
#endif

int main() {
    int K;
    cin >> K;

    for(int i = 0; i < K; i++){
        cout << (char)('A' + i);
    }

    cout << endl;
}