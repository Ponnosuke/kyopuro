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

i64 get_mex(i64 A_i, i64 A_j, i64 A_k){
    i64 ret = 0;
    for(i64 num = 0; num <= 3; num++){
        bool OK = true;

        if(A_i == num){
            OK = false;
            continue;
        }
        if(A_j == num){
            OK = false;
            continue;
        }
        if(A_k == num){
            OK = false;
            continue;
        }

        if(OK){
            ret = num;
            break;
        }
    }

    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    string S;
    cin >> S;

    vector<vector<int>> cnt_M(N+1, vector<int>(3, 0)), cnt_X(N+1, vector<int>(3, 0));
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'M'){
            cnt_M.at(i).at(A.at(i))++;
        }
        if(S.at(i) == 'X'){
            cnt_X.at(i).at(A.at(i))++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cnt_M.at(i+1).at(j) += cnt_M.at(i).at(j);
            cnt_X.at(i+1).at(j) += cnt_X.at(i).at(j);
        }
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'E'){
            int Aj = A.at(i);

            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    i64 L_cnt = cnt_M.at(i).at(j);
                    i64 R_cnt = cnt_X.at(N).at(k) - cnt_X.at(i).at(k);
                    ans += (L_cnt * R_cnt * get_mex(j, Aj, k));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}