#include <bits/stdc++.h>
#include <atcoder/dsu>

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

int dist2(int x1, int y1, int x2, int y2){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X.at(i) >> Y.at(i);
    }

    atcoder::dsu uf(N);
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(dist2(X.at(i), Y.at(i), X.at(j), Y.at(j)) <= D*D){
                uf.merge(i, j);
            }
        }
    }

    int target = uf.leader(0);
    for(int i = 0; i < N; i++){
        if(target == uf.leader(i)){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }

    return 0;
}