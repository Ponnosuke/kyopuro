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
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> cnt(2000000 + 1, 0);  // 1 := true, 0 := false
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cnt.at(A.at(i)*A.at(i) + A.at(j)*A.at(j)) = 1;
        }
    }

    bool OK = false;
    for(int i = 0; i <= M; i++){
        if(cnt.at(i) == 1 && cnt.at(M-i) == 1){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}