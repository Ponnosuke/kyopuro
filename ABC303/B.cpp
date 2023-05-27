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
    vector<vector<int>> a(M, vector<int>(N, 0));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> a.at(i).at(j);
        }
    }

    vector<vector<bool>> isOK(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N-1; j++){
            int now = a.at(i).at(j), nxt = a.at(i).at(j+1);
            now--;
            nxt--;
            isOK.at(now).at(nxt) = true;
            isOK.at(nxt).at(now) = true;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(!isOK.at(i).at(j)){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}