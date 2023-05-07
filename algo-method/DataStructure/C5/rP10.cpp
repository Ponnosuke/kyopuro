/*
    AC
    
    O(Q + MlogM + MlogM)
    かな
*/

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
    vector<int> cnt(500000 + 1, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        cnt.at(A.at(i))++;
    }

    map<int, int> memo;
    int Q;
    cin >> Q;

    while(Q--){
        int x;
        cin >> x;

        if(memo.count(x)){
            cout << memo.at(x) << '\n';
        }
        else{
            int ans = 0;
            for(int i = x; i <= 500000; i += x){
                ans += cnt.at(i);
            }

            memo[x] = ans;
            cout << ans << '\n';
        }
    }
}