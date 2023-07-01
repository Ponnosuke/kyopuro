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
    vector<string> C(N);
    for(int i = 0; i < N; i++){
        cin >> C.at(i);
    }
    vector<string> D(M+1);
    for(int i = 1; i <= M; i++){
        cin >> D.at(i);
    }
    vector<int> P(M+1);
    for(int i = 0; i <= M; i++){
        cin >> P.at(i);
    }

    map<string, int> price;
    for(int i = 1; i <= M; i++){
        price[D.at(i)] = P.at(i);
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(!price.count(C.at(i))){
            ans += P.at(0);
        }
        else{
            ans += price[C.at(i)];
        }
    }

    cout << ans << endl;
}