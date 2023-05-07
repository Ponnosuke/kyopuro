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
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X.at(i) >> Y.at(i);
    }
    string S;
    cin >> S;

    map<int, int> L, R;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'R'){
            if(R.count(Y.at(i))){
                R.at(Y.at(i)) = min(R[Y.at(i)], X.at(i));
            }
            else{
                R[Y.at(i)] = X.at(i);
            }
        }
        else{
            if(L.count(Y.at(i))){
                L.at(Y.at(i)) = max(L[Y.at(i)], X.at(i));
            }
            else{
                L[Y.at(i)] = X.at(i);
            }

        }
    }

    bool OK = false;
    for(auto [RY, RX] : R){
        if(L.count(RY)){
            if(L.at(RY) > RX){
                OK = true;
                break;
            }
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}