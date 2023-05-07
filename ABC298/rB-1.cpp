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

//  N+1-j, i      N+1-(j+1) - 1
//  N-1-j, i

vector<vector<int>> vecRotate(const vector<vector<int>> &A, int N){
    vector<vector<int>> ret(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ret.at(i).at(j) = A.at(N-1-j).at(i);
        }
    }

    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0)), B(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> B.at(i).at(j);
        }
    }

    bool OK = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A.at(i).at(j) == 1 && B.at(i).at(j) != 1){
                OK = false;
                break;
            }
        }

        if(!OK){
            break;
        }
    }

    if(OK){
        cout << "Yes" << endl;

        return 0;
    }

    for(int rep = 0; rep < 3; rep++){
        vector<vector<int>> ret = vecRotate(A, N);

        OK = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(ret.at(i).at(j) == 1 && B.at(i).at(j) != 1){
                    OK = false;
                    break;
                }
            }

            if(!OK){
                break;
            }
        }

        if(OK){
            break;
        }

        A = ret;
    }

    cout << (OK ? "Yes" : "No") << endl;


    return 0;
}