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
    map<string, int> mp;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        mp[S]++;
    }
    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;
        string T;
        cin >> T;

        if(type == 0){
            mp[T]++;
        }
        if(type == 1){
            mp[T] = 0;
        }
        if(type == 2){
            cout << mp[T] << '\n';
        }
    }

    return 0;
}