// メモ化再帰

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15;


vector<int> h(100010);

// 0-indexed
map<int, i64> memo;  // key: 足場  value: 最小コスト
// 足場 i に辿り着くまでに支払うコストの総和の最小値を求める関数
i64 minCost(int i){
    if(memo.count(i))  return memo.at(i);

    i64 ret = INF;
    if(i == 0){
        ret = 0;
    }
    else if(i == 1){
        ret = abs(h.at(1) - h.at(0));
    }
    else{
        ret = min(minCost(i-1) + abs(h.at(i) - h.at(i-1)), minCost(i-2) + abs(h.at(i) - h.at(i-2)));
    }

    memo[i] = ret;
    return ret;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)  cin >> h.at(i);
    N--;

    cout << minCost(N) << endl;

    return 0;
}