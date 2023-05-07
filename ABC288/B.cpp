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
    int N, K;
    cin >> N >> K;
    vector<string> S(K);
    for(int i = 0; i < K; i++){
        cin >> S.at(i);
    }

    sort(S.begin(), S.end());

    for(int i = 0; i < K; i++){
        cout << S.at(i) << '\n';
    }
}