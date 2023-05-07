#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i = 1; i < N; i++)  cin >> A.at(i);

    vector<vector<int>> box(N);
    for(int i = 1; i <= N-1; i++){
        box.at(A.at(i)).push_back(i);
    }

    for(int i = 0; i < box.size(); i++){
        debugL(i);
        for(int j = 0; j < box.at(i).size(); j++){
            debug(box.at(i).at(j));
        }
        debugP();
    }

    queue<int> Q;
    Q.push(0);
    bool stop = false;
    vector<int> ans(N, 0);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        debug(v);

        for(int vertex : box.at(v)){
            Q.push(vertex);

            debug(vertex);

            ans.at(vertex) = ans.at(v) + 1;
            if(vertex == X){
                stop = true;
            }
        }

        debugP();

        if(stop){
            debugP(STOP);

            break;
        }
    }

    cout << ans.at(X) << '\n';
}