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
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> take(N, 0);
    for(int i = 3; i < N; i++){
        take.at(i) = 1;
    }

    i64 cnt = 0;
    do{
        vector<i64> Ai(3, 0);
        i64 index = 0;
        for(int i = 0; i < N; i++){
            if(take.at(i) == 0){
                Ai.at(index) = A.at(i);
                index++;
            }
        }

        

        if(A.at(0) % A.at(1) == 0){
            if((A.at(0)/A.at(1)) == A.at(2)){
                cnt++;
            }
        }
        if(A.at(0) % A.at(2) == 0){
            if((A.at(0)/A.at(2)) == A.at(1)){
                cnt++;
            }
        }
        if(A.at(1) % A.at(0) == 0){
            if((A.at(1)/A.at(0)) == A.at(2)){
                cnt++;
            }
        }
        if(A.at(1) % A.at(2) == 0){
            if((A.at(1)/A.at(2)) == A.at(0)){
                cnt++;
            }
        }
        if(A.at(2) % A.at(0) == 0){
            if((A.at(2)/A.at(0)) == A.at(1)){
                cnt++;
            }
        }
        if(A.at(2) % A.at(1) == 0){
            if((A.at(2)/A.at(1)) == A.at(0)){
                cnt++;
            }
        }

    } while(next_permutation(take.begin(), take.end()));

    cout << cnt << '\n';

    return 0;
}