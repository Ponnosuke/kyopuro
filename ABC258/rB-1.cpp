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

vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    debugP();
    i64 N;
    cin >> N;
    debugP();
    vector<vector<i64>> A(N, vector<i64>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char ch;
            cin >> ch;
            A.at(i).at(j) = (i64)(ch - '0');
        }
    }

    debugP();
    i64 ans = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            for(int dir = 0; dir < 8; dir++){
                i64 now = A.at(y).at(x);
                debugV(y);
                debugVL(x);
                int nx = x, ny = y;
                for(int rep = 0; rep < N-1; rep++){
                    now *= 10;
                    nx = (nx + dx.at(dir) + N) % N, ny = (ny + dy.at(dir) + N) % N;
                    debugV(ny);
                    debugVL(nx);
                    now += A.at(ny).at(nx);
                }

                debugVL(now);
                ans = max(ans, now);
                debugWL();
            }
        }
    }
    debugP();

    cout << ans << endl;
}