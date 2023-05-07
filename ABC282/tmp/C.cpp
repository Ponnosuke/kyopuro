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
    string S;
    cin >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(S.at(i) == '"'){

            // debug
            debugP(point29);

            cnt++;
        }
        if(S.at(i) == ','){

            // debug
            debugP(point36);

            if(cnt % 2 == 0){
                S.at(i) = '.';
            }
        }
    }

    cout << S << '\n';

    return 0;
}