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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    vector<vector<int>> slot(N, vector<int>(10, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            slot.at(i).at(j) = (int)(S.at(i).at(j) - '0');
        }
    }

    int ans = INF;
    for(int num = 0; num <= 9; num++){
        vector<int> cnt(10, 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 10; j++){
                if(slot.at(i).at(j) == num){
                    cnt.at(j)++;
                    break;
                }
            }
        }

        int t = 0;
        for(int i = 0; i < 10; i++){
            t = max(t, i + 10 * (cnt.at(i) - 1));
        }

        ans = min(ans, t);
    }

    cout << ans << '\n';
}