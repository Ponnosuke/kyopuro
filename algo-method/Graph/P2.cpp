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
    vector<vector<int>> follow(N);

    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        follow.at(A).push_back(B);
    }

    for(int i = 0; i < N; i++){
        sort(follow.at(i).begin(), follow.at(i).end());

        int vecSize = follow.at(i).size();
        for(int j = 0; j < vecSize; j++){
            cout << follow.at(i).at(j);
            if(j < vecSize - 1){
                cout << " ";
            }
        }

        cout << '\n';
    }
}