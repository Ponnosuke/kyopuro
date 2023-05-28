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
    vector<i64> target;

    for(int i = 0; i < 60; i++){
        for(int j = i+1; j < 60; j++){
            for(int k = j+1; k < 60; k++){
                target.push_back((1LL << i) + (1LL << j) + (1LL << k));
            }
        }
    }

    sort(target.begin(), target.end());

    int T;
    cin >> T;
    while(T--){
        i64 N;
        cin >> N;

        auto itr = upper_bound(target.begin(), target.end(), N);

        if(itr == target.begin()){
            cout << -1 << '\n';
        }
        else{
            advance(itr, -1);
            cout << *itr << '\n';
        }
    }

    return 0;
}