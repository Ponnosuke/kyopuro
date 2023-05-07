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
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;

        graph.at(A).push_back(B);
        graph.at(B).push_back(A);
    }

    set<int> aruru;
    for(int num : graph.at(X)){
        aruru.insert(num);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(i == X){
            continue;
        }

        bool OK1 = false, OK2 = true;
        for(int num : graph.at(i)){
            if(aruru.count(num)){
                OK1 = true;
            }
            if(num == X){
                OK2 = false;
            }
        }

        if(OK1 && OK2){
            ans++;
        }
    }

    cout << ans << '\n';
}