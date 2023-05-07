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
    int T;
    cin >> T;
    for(int rep = 0; rep < T; rep++){
        int N;
        cin >> N;
        vector<i64> A(N);
        for(int i = 0; i < N; i++){
            cin >> A.at(i);
        }

        int cnt = 0;
        for(auto ele : A){
            if(ele % 2 != 0){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}