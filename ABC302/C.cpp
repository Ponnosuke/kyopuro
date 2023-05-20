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
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    vector<int> P(N, 0);
    for(int i = 0; i < N; i++){
        P.at(i) = i;
    }


    bool OK = false;
    do{
        bool OK1 = true;
        for(int i = 0; i < N-1; i++){
            int diff = 0;
            for(int j = 0; j < M; j++){
                if(S.at(P.at(i)).at(j) != S.at(P.at(i+1)).at(j)){
                    diff++;
                }

                if(diff > 1){
                    OK1 = false;
                    break;
                }
            }

            if(!OK1){
                break;
            }
        }

        if(OK1){
            OK = true;
            break;
        }
    }while(next_permutation(P.begin(), P.end()));

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}