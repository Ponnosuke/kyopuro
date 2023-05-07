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

int main() {
    int N, M;
    cin >> N >> M;

    atcoder::dsu uf(2*N);
    vector<int> Rcnt(2*N, 0);
    for(int i = 0; i < N; i++){
        uf.merge(i, i+N);
    }

    for(int i = 0; i < M; i++){
        int A, C;
        char B, D;
        cin >> A >> B >> C >> D;
        A--;
        C--;
        if(B == 'B'){
            A += N;
        }
        if(D == 'B'){
            C += N;
        }

        if(uf.same(A, C)){
            Rcnt.at(uf.leader(A))++;
        }
        uf.merge(A, C);
    }

    int ring = 0, notRing = 0;
    for(int i = 0; i < 2*N; i++){
        if(uf.leader(i) == i){
            if(Rcnt.at(i) > 0){
                ring++;
            }
            else{
                notRing++;
            }
        }
    }

    cout << ring << " " << notRing << endl;
}