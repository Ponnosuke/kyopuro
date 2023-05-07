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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(K+1);
    for(int i = 1; i <= K; i++){
        cin >> A.at(i);
    }
    vector<int> L(Q+1);
    for(int i = 1; i <= Q; i++){
        cin >> L.at(i);
    }

    vector<int> field(N+2, 0);  // 1 := true,  0 := false
    field.at(N+1) = 1;
    for(int i = 1; i <= K; i++){
        field.at(A.at(i)) = 1;
    }
    for(int i = 1; i <= Q; i++){
        int pos = A.at(L.at(i));
        if(field.at(pos + 1) != 1){
            field.at(pos) = 0;
            field.at(pos + 1) = 1;
            A.at(L.at(i)) = pos + 1;
        }
    }

    for(int i = 1; i <= K; i++){
        cout << A.at(i);

        if(i < K){
            cout << " ";
        }
    }
    cout << '\n';
}