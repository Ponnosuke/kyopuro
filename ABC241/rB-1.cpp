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
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<int> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }

    bool OK = true;
    vector<bool> used(N, false);
    for(int i = 0; i < M; i++){
        bool found = false;
        for(int j = 0; j < N; j++){
            if((B.at(i) == A.at(j)) && !used[j]){
                used[j] = true;
                found = true;
                break;
            }
        }

        if(!found){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}