#include <bits/stdc++.h>
#include <atcoder/dsu>

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
    vector<vector<bool>> Tak(N, vector<bool>(N, false)), Ao(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        Tak.at(A).at(B) = true;
        Tak.at(B).at(A) = true;
    }
    for(int i = 0; i < M; i++){
        int C, D;
        cin >> C >> D;
        C--;
        D--;
        Ao.at(C).at(D) = true;
        Ao.at(D).at(C) = true;
    }

    bool OK = false;
    vector<int> seq(N, 0);
    for(int i = 1; i < N; i++){
        seq.at(i) = i;
    }
    do{
        bool areSame = true; 
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(Tak.at(i).at(j) != Ao.at(seq.at(i)).at(seq.at(j))){
                    areSame = false;
                    break;
                }
            }
            if(!areSame){
                break;
            }
        }

        if(areSame){
            OK = true;
            break;
        }
    }while(next_permutation(seq.begin(), seq.end()));

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}