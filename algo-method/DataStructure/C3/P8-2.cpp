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
    int N;
    cin >> N;
    string T;
    cin >> T;

    map<int, set<string>> mp;
    for(int i = 0; i < N; i++){
        int M;
        cin >> M;
        for(int j = 0; j < M; j++){
            string S;
            cin >> S;
            mp[i].insert(S);
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(mp.at(i).count(T)){
            cnt++;
        }
    }

    cout << cnt << '\n';
}