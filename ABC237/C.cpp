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
    string S;
    cin >> S;

    int N = S.size();

    int l = 0, r = N - 1;
    while(l < N && S.at(l) == 'a'){
        l++;
    }

    if(l == N){
        cout << "Yes" << endl;

        return 0;
    }

    while(r >= 0 && S.at(r) == 'a'){
        r--;
    }

    if(l > (N-1-r)){
        cout << "No" << endl;

        return 0;
    }

    bool OK = true;
    for(int i = 0; i <= (r-l)/2; i++){
        if(S.at(l+i) != S.at(r-i)){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}