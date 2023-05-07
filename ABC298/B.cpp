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
    vector<vector<int>> A(N+1, vector<int>(N+1, 0)), B(N+1, vector<int>(N+1, 0));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A.at(i).at(j);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> B.at(i).at(j);
        }
    }

    bool OK = true;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(A.at(i).at(j) == 1 && B.at(i).at(j) == 0){
                OK = false;
            }
        }
    }

    if(OK){
        cout << "Yes" << endl;

        return 0;
    }

    vector<vector<int>> copyA(N+1, vector<int>(N+1, 0));
    copyA = A;
    vector<vector<int>> flag(N+1, vector<int>(N+1, 0));
    for(int rep = 0; rep < 3; rep++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                A.at(i).at(j) = copyA.at(N+1-j).at(i);
            }
        }

        // debug
        // debugWL(A);
        // for(int i = 1; i <= N; i++){
        //     for(int j = 1; j <= N; j++){
        //         debug(A.at(i).at(j));
        //     }
        //     debugWL();
        // }
        // debugWL();

        OK = true;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(A.at(i).at(j) == 1 && B.at(i).at(j) == 0){
                    OK = false;
                }
            }
        }

        if(OK){
            cout << "Yes" << endl;

            return 0;
        }

        copyA = A;
    }

    cout << "No" << endl;
}