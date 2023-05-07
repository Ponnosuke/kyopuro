/*
    queue を用いた尺取り法の実装の別例

    034 - There are few types of elements（★4） 
    https://atcoder.jp/contests/typical90/tasks/typical90_ah 
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
    int K;
    cin >> N >> K;
    vector<int> a(N, 0);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    unordered_map<int, int> ump;
    queue<int> Q;
    int ans = -1, cnt = 0, flag = 0;
    for(int ele : a){
        Q.push(ele);
        ump[ele]++;
        if(ump.at(ele) == 1){
            flag++;
        }
        cnt++;

        // 部分列が条件を満たさない時、左から削っていく
        while(flag > K && !Q.empty()){
            int v = Q.front();
            Q.pop();
            cnt--;
            ump.at(v)--;
            if(ump.at(v) == 0){
                flag--;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}