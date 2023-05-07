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

    vector<int> A(M, 0);
    for(int i = N; i < M; i++){
        A.at(i) = 1;
    }

    do{

        // debug
        // debugWL(A);
        // for(int i = 0; i < M; i++){
        //     debug(A.at(i));
        // }
        // debugWL();

        for(int i = 0; i < M; i++){
            if(A.at(i) == 0){
                cout << i+1 << " ";
            }
        }
        cout << '\n';
    } while(next_permutation(A.begin(), A.end()));

    return 0;
}