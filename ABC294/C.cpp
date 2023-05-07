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
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N), B(M), C(N+M);
    set<i64> Ast, Bst;
    for(int i = 0; i < N; i++){
        int tmpA;
        cin >> tmpA;
        A.at(i) = tmpA;
        Ast.insert(tmpA);
        C.at(i) = tmpA;
    }
    for(int i = 0; i < M; i++){
        int tmpB;
        cin >> tmpB;
        B.at(i) = tmpB;
        Bst.insert(tmpB);
        C.at(i+N) = tmpB;
    }
    sort(C.begin(), C.end());

    // debug
    // for(int i = 0; i < N+M; i++){
    //     debug(C.at(i));
    // }
    // debugWL();

    vector<i64> ansA, ansB;
    for(int i = 0; i < N+M; i++){
        i64 now = C.at(i);

        if(Ast.count(now)){
            ansA.push_back(i+1);
        }
        else{
            ansB.push_back(i+1);
        }
    }

    // i64 ansAsize = ansA.size(), ansBsize = ansB.size();
    for(int i = 0; i < N; i++){
        cout << ansA.at(i);

        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
    for(int i = 0; i < M; i++){
        cout << ansB.at(i);

        if(i < M-1){
            cout << " ";
        }
    }
    cout << '\n';
}