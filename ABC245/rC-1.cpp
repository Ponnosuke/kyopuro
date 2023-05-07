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
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N), B(N);
    for(i64 i = 0; i < N; i++)  cin >> A.at(i);
    for(i64 i = 0; i < N; i++)  cin >> B.at(i);

    if(N == 1){
        cout << "Yes" << '\n';

        return 0;
    }

    bool OK = false;
    bool OK_A = true, OK_B = true;
    for(i64 i = 0; i < N-1; i++){
        bool nxOK_A = false, nxOK_B = false;
        if(OK_A){
            if(abs(A.at(i+1) - A.at(i)) <= K){
                nxOK_A = true;
            }
            if(abs(B.at(i+1) - A.at(i)) <= K){
                nxOK_B = true;
            }
        }
        if(OK_B){
            if(abs(A.at(i+1) - B.at(i)) <= K){
                nxOK_A = true;
            }
            if(abs(B.at(i+1) - B.at(i)) <= K){
                nxOK_B = true;
            }
        }

        if(i+1 == N-1){
            if(nxOK_A || nxOK_B){
                OK = true;
                break;
            }
        }

        OK_A = nxOK_A;
        OK_B = nxOK_B;
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}