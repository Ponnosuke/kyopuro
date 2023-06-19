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
    i64 N, M;
    cin >> N >> M;
    vector<vector<i64>> A(N, vector<i64>(M, -1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A.at(i).at(j);
        }
    }

    for(int i = 0; i < N; i++){
        sort(A.at(i).begin(), A.at(i).end());
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            debugV(i);
            debugVL(j);

            i64 ret = 0;
            for(int k = 0; k < M; k++){
                i64 now_value = A.at(i).at(k);
                i64 add = distance(A.at(j).begin(), lower_bound(A.at(j).begin(), A.at(j).end(), now_value));

                debugV(add);
                debugVL(k);

                ret += (add + k + 1);
            }

            debugVL(ret);

            ans += ret;
        }
    }

    cout << ans << '\n';
}