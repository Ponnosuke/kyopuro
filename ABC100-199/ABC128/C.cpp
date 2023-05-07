#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> isConnected(M, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int s;
            cin >> s;
            s--;

            isConnected.at(i).at(s) = true;
        }
    }
    vector<int> p(M, 0);
    for(int i = 0; i < M; i++){
        cin >> p.at(i);
    }

    int ans = 0;
    for(int swi = 0; swi < (1 << N); swi++){
        vector<int> cnt(M, 0);
        for(int j = 0; j < N; j++){
            if((swi >> j) & 1){
                for(int light = 0; light < M; light++){
                    if(isConnected.at(light).at(j)){
                        cnt.at(light)++;
                    }
                }
            }
        }

        bool OK = true;
        for(int light = 0; light < M; light++){
            if(cnt.at(light) % 2 != p.at(light)){
                OK = false;
                break;
            }
        }

        if(OK){
            ans++;
        }
    }

    cout << ans << endl;
}