/*
This code was written by hamayanhamayan.

About ABC076.

queue を使って愚直にシミュレートする方法
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define INF INT_MAX/2
int N, K;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
 
    queue<int> que;
    que.push(1);
 
    rep(i, 0, N) {
        queue<int> q;
 
        while (!que.empty()) {
            int x = que.front(); que.pop();
            q.push(x * 2);
            q.push(x + K);
        }
 
        swap(que, q);
    }
 
    int ans = INF;
    while (!que.empty()) {
        int x = que.front(); que.pop();
        ans = min(ans, x);
    }
    cout << ans << endl;
}