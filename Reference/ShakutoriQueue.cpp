/*
    queue を用いたしゃくとり法の実装
    C - 列 https://atcoder.jp/contests/abc032/tasks/abc032_c 
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
    i64 K;
    cin >> K;
    vector<i64> S(N, -1);
    bool isZero = false;
    for(int i = 0; i < N; i++){
        cin >> S.at(i);

        if(S.at(i) == 0){
            isZero = true;
        }
    }

    if(isZero){
        cout << N << '\n';
        return 0;
    }

    queue<i64> Q;
    i64 flag = 1;
    i64 ans = -1;
    for(i64 ele : S){
        Q.push(ele);
        flag *= ele;

        // 部分列が条件を満たすようになるまで左を削る
        // 一応の queue が空の時に pop しないようにする処理
        // 空集合が条件を満たすことが多いので、気にしなくていい場合が多い
        while(flag > K && !Q.empty()){
            i64 v = Q.front();
            Q.pop();
            flag /= v;
        }

        ans = max(ans, (i64)Q.size());
    }

    cout << ans << '\n';
}