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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> cnt(N, 0);
    for(int i  = 0; i < M; i++){
        int F, S;
        cin >> F >> S;
        G.at(F).push_back(S);
        cnt.at(S)++;
    }

    queue<int> Q;
    int num = 0;
    for(int i = 0; i < N; i++){
        if(cnt.at(i) == 0){
            Q.push(i);
            num++;
        }
    }

    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        for(int nv : G.at(v)){
            cnt.at(nv)--;
            if(cnt.at(nv) == 0){
                Q.push(nv);
                num++;
            }
        }
    }

    if(num == N){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}