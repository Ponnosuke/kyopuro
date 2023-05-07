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
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    queue<int> Q;
    vector<bool> isExisted(100000 + 1, false);
    int ans = 0;
    for(int now : A){
        while(isExisted.at(now)){
            isExisted.at(Q.front()) = false;
            Q.pop();
        }

        Q.push(now);
        isExisted.at(now) = true;
        ans = max(ans, (int)Q.size());
    }

    cout << ans << endl;
}