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
    vector<vector<int>> g(N);
    vector<int> cnt(N, 0);

    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;

        cnt.at(A)++;
        cnt.at(B)++;
        g.at(A).push_back(B);
        g.at(B).push_back(A);
    }

    int index = 0, now = -1;
    for(int i = 0; i < N; i++){
        if(now < cnt.at(i)){
            index = i;
            now = cnt.at(i);
        }
    }

    sort(g.at(index).begin(), g.at(index).end());
    for(int i = 0; i < now; i++){
        cout << g.at(index).at(i);
        if(i < now-1){
            cout << " ";
        }
    }
    cout << '\n';
}