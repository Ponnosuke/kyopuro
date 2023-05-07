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
    vector<string> S(N);
    set<string> T;
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }
    for(int i = 0; i < M; i++){
        string inT;
        cin >> inT;
        T.insert(inT);
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        string now = S.at(i).substr(3, 3);
        if(T.count(now)){
            ans++;
        }
    }

    cout << ans << '\n';
}