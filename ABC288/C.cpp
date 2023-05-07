#include <bits/stdc++.h>
#include <atcoder/dsu>
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
    // vector<vector<int>> G(N);
    atcoder::dsu uf(N);
    int ans = 0;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;

        if(uf.same(A, B)){
            ans++;
        }

        uf.merge(A, B);
        // G.at(A).push_back(B);
        // G.at(B).push_back(A);
    }

    cout << ans << '\n';
}