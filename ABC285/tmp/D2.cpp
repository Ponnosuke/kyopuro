#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

int main() {
    i64 N;
    cin >> N;
    vector<string> S(N), T(N);
    set<string> Sset, Tset;
    for(int i = 0; i < N; i++){
        cin >> S.at(i) >> T.at(i);
        Sset.insert(S.at(i));
        Tset.insert(T.at(i));
    }

    bool OK = false;
    for(auto ele : Tset){
        if(!Sset.count(ele)){
            OK = true;
            break;
        }
    }

    if(!OK){
        cout << "No" << '\n';
    }
    else{
        cout << "Yes" << '\n';
    }
}