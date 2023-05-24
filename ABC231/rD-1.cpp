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
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }

    atcoder::dsu uf(N);
    vector<int> dig(N, 0);
    bool OK = true;
    for(int i = 0; i < M; i++){
        if(uf.same(A.at(i), B.at(i))){
            OK = false;
            break;
        }

        uf.merge(A.at(i), B.at(i));
        dig.at(A.at(i))++;
        dig.at(B.at(i))++;

        if(dig.at(A.at(i)) > 2 || dig.at(B.at(i)) > 2){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}