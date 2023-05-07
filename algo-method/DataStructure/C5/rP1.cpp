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
    int N;
    cin >> N;
    vector<int> cnt(200001, 0);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        cnt.at(A)++;
    }

    int Q;
    cin >> Q;
    while(Q--){
        int x;
        cin >> x;
        cout << cnt.at(x) << '\n';
    }
}