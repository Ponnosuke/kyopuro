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
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;

    while(Q > 0){
        Q--;

        int x;
        cin >> x;
        auto itrL = lower_bound(A.begin(), A.end(), x);
        auto itrR = upper_bound(A.begin(), A.end(), x);
        int ans = distance(itrL, itrR);
        cout << ans << '\n';
    }
}