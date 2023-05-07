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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> S(M);
    vector<int> Cs(M);
    for(int i = 0; i < M; i++){
        int C;
        cin >> C;
        Cs[i] = C;
        for(int j = 0; j < C; j++){
            int a;
            cin >> a;
            S[i].push_back(a);
        }
    }

    int ans = 0;
    for(int tmp = 0; tmp < (1 << 10); tmp++){
        bitset<10> bs(tmp);

        bool OK = true;
        vector<bool> isExisted(N+1, false);
        for(int i = 0; i < M; i++){
            if(bs.test(i)){
                for(int j = 0; j < Cs[i]; j++){
                    isExisted[S[i][j]] = true;
                }
            }
        }

        for(int num = 1; num <= N; num++){
            if(!isExisted[num]){
                OK = false;
                break;
            }
        }

        if(OK){
            ans++;
        }

        if(tmp >= (1 << M) - 1){
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}