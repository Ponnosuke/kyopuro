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
    vector<int> A(N, -1);
    for(int i = 1; i <= N-1; i++){
        cin >> A.at(i);
    }
    int v;
    cin >> v;

    vector<vector<int>> children(N);
    for(int i = 1; i <= N-1; i++){
        children.at(A.at(i)).push_back(i);
    }

    int cnt = 0;
    queue<int> Q;
    Q.push(v);
    while(!Q.empty()){
        int ver = Q.front();
        Q.pop();

        for(int nxt_ver : children.at(ver)){
            Q.push(nxt_ver);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}