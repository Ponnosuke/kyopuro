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
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }

    vector<bool> isExisted(N+1, false);
    int nowMin = INF;
    for(int i = 0; i < K; i++){
        nowMin = min(nowMin, P.at(i));
        isExisted.at(P.at(i)) = true;
    }

    cout << nowMin << '\n';
    for(int i = K; i < N; i++){
        if(nowMin < P.at(i)){
            isExisted.at(P.at(i)) = true;

            nowMin++;
            while(!isExisted.at(nowMin)){
                nowMin++;
            }
        }

        cout << nowMin << '\n';
    }

    return 0;
}