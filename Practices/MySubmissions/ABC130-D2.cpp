#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    i64 N, K;
    cin >> N >> K;
    queue<i64> A;
    for(int i = 0; i < N; i++){
        i64 tmp;
        cin >> tmp;
        A.push(tmp);
    }

    queue<i64> Q;
    i64 flag = 0;
    i64 cnt = 0;
    while(!A.empty()){        
        i64 now = A.front();
        A.pop();
        flag += now;
        Q.push(now);

        while(flag >= K && !Q.empty()){
            cnt += ((i64)A.size() + 1);
            flag -= Q.front();
            Q.pop();
        }

        debugV(now);
        debugVL(flag);
    }

    cout << cnt << '\n';
}