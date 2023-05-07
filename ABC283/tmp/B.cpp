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
    int N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++)  cin >> A.at(i);
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int query;
        cin >> query;

        if(query == 1){
            int k;
            i64 x;
            cin >> k >> x;
            k--;
            A.at(k) = x;
        }
        else{
            int k;
            cin >> k;
            k--;
            cout << A.at(k) << '\n';
        }
    }
}