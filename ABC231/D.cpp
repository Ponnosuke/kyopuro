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
    vector<int> dig(N, 0);
    atcoder::dsu uf(N);
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++){
        int iA, iB;
        cin >> iA >> iB;
        iA--;
        iB--;

        dig.at(iA)++;
        dig.at(iB)++;

        uf.merge(iA, iB);

        A.at(i) = iA;
        B.at(i) = iB;
    }

    vector<int> Edge(N, 0);
    for(int i = 0; i < M; i++){
        Edge.at(uf.leader(A.at(i)))++;
    }

    bool OK1 = true;
    for(int i = 0; i < N; i++){
        if(dig.at(i) > 2){
            OK1 = false;
            break;
        }
    }

    bool OK2 = true;
    for(int i = 0; i < N; i++){
        if(Edge.at(i) == uf.size(i)){

            OK2 = false;
            break;
        }
    }

    if(OK1 && OK2){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }

    return 0;
}