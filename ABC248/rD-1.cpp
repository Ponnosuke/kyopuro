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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int Q;
    cin >> Q;
    
    vector<vector<int>> idx(201010);
    for(int i = 0; i < N; i++){
        idx.at(A.at(i)).push_back(i);
    }

    while(Q--){
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        R--;
        auto itrL = lower_bound(idx.at(X).begin(), idx.at(X).end(), L);
        auto itrR = upper_bound(idx.at(X).begin(), idx.at(X).end(), R);
        int cnt = distance(itrL, itrR);

        cout << cnt << endl;
    }
}