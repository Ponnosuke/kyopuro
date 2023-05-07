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
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    bool routeA = false;
    for(int i = 0; i < N; i++){
        cin >> C.at(i);

        if(C.at(i) == T){
            routeA = true;
        }
    }
    for(int i = 0; i < N; i++){
        cin >> R.at(i);
    }

    int ans = -1;
    int maxNum = -1;
    for(int i = 0; i < N; i++){
        if(routeA){
            if(C.at(i) == T){
                if(maxNum < R.at(i)){
                    maxNum = R.at(i);
                    ans = i+1;
                }
            }
        }
        else{
            if(C.at(i) == C.at(0)){
                if(maxNum < R.at(i)){
                    maxNum = R.at(i);
                    ans = i+1;
                }
            }
        }
    }

    cout << ans << endl;
}