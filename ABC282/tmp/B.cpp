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
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++)  cin >> S.at(i);

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            bool OK = true;
            string str1 = S.at(i), str2 = S.at(j);

            debug(str1);
            debugL(str2);

            for(int k = 0; k < M; k++){
                if(str1.at(k) == 'x' && str2.at(k) == 'x'){

                    debugP("routeA");

                    OK = false;
                    break;
                }
            }

            if(OK){
                ans++;
            }
        }
    }

    cout << ans << '\n';
}