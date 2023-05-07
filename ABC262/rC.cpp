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
    vector<i64> a(N, 0);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        a.at(i)--;
    }

    // debug
    debugWL(a);
    for(int i = 0; i < N; i++){
        debug(a.at(i));
    }
    debugWL();

    vector<i64> S(N, 0);
    vector<bool> isSame(N, false);
    for(int i = 0; i < N; i++){
        if(a.at(i) == i){
            debugV(i);
            debugVL(a.at(i));

            S.at(i)++;
            isSame.at(i) = true;
        }
    }
    for(int i = 0; i < N-1; i++){
        S.at(i+1) += S.at(i);
    }

    // debug
    debugWL(isSame);
    for(int i = 0; i < N; i++){
        if(isSame.at(i)){
            debugVL(i);
        }
    }
    debugWL();
    debugWL(S.at(i));
    for(int i = 0; i < N; i++){
        debugVL(S.at(i));
    }

    i64 cnt = 0;
    for(int i = 0; i < N; i++){
        if(isSame.at(i)){
            cnt += (S.at(N-1) - S.at(i));
        }
        else{
            if(a.at(a.at(i)) == i && a.at(i) > i){
                cnt++;
            }
        }
    }

    cout << cnt << endl;   
}