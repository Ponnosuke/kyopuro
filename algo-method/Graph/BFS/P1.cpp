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
  vector<vector<int>> graph(N);
  for(int i = 0; i < M; i++){
    int A, B;
    cin >> A >> B;
    graph.at(A).emplace_back(B);
    graph.at(B).emplace_back(A);
  }

  map<int, set<int>> mp;
  vector<bool> seen(N, false);
  vector<int> dist(N, -1);
  queue<int> Q;
  Q.emplace(0);
  mp[0].insert(0);
  dist.at(0) = 0;
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    for(int nv : graph.at(v)){
      if(dist.at(nv) != -1){
        continue;
      }

      Q.emplace(nv);
      dist.at(nv) = dist.at(v) + 1;
    }
  }

  for(int i = 0; i < N; i++){
    mp[dist.at(i)].insert(i);
  }

  for(auto [k, vertex] : mp){
    if(k == -1){
      continue;
    }
    for(auto ele : vertex){
      cout << ele << " ";
    }
    cout << '\n';
  }

}