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
    i64 N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    
    vector<i64> cnt(26, 0), prevIdx(26, -1);
    i64 cntA = 0, cntB = 0;
    for(int i = 0; i < N; i++){
        int now = S.at(i) - 'a';
        cnt.at(now)++;
        if(cnt.at(now) == 2){
            if(i == (N/2) || prevIdx.at(now) == (N/2)){
                if(N % 2 == 1){
                    if(i == (N/2)){
                        swap(S.at(i), S.at(N - prevIdx.at(now)));
                        cnt.at(S.at(i))++;
                    }
                }
            }

            cnt.at(now) -= 2;
        }
        else{
            prevIdx.at(now) = i;
        }
    }
}