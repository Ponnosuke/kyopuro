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
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    P--;
    Q--;
    R--;
    S--;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int k = S - Q;
    for(int i = P; i <= Q; i++){
        swap(A.at(i), A.at(i+k));
    }

    for(int i = 0; i < N; i++){
        cout << A.at(i);
        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
}