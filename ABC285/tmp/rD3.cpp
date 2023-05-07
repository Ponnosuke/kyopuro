#include <bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;

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
    dsu uf(2*N);
    map<string, int> index;
    int cnt = 0;
    bool OK = true;
    for(int i = 0; i < N; i++){
        string S, T;
        cin >> S >> T;
        if(!index.count(S)){
            index[S] = cnt;
            cnt++;
        }
        if(!index.count(T)){
            index[T] = cnt;
            cnt++;
        }

        int idxS = index.at(S), idxT = index.at(T);
        if(uf.same(idxS, idxT)){
            OK = false;
            break;
        }
        else{
            uf.merge(idxS, idxT);
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}