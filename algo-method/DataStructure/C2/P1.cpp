#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    cout << A[k] << endl;
    cout << A[N-1-k] << endl;
}