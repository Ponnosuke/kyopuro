#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<vector<int>> tree(N);
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree.at(u).push_back(v);
        tree.at(v).push_back(u);
    }

    vector<bool> seen(N, false);
    queue<int> Q;
    map<int, int> rec;
    Q.push(X);
    seen.at(X) = true;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        seen.at(now) = true;

        for(int nxt : tree.at(now)){
            if(!seen.at(nxt)){
                Q.push(nxt);
                rec[nxt] = now;
            }
        }
    }

    stack<int> ans;
    int nowV = Y;
    ans.push(Y);
    while(nowV != X){
        ans.push(rec.at(nowV));
        nowV = rec.at(nowV);
    }

    while(!ans.empty()){
        int numV = ans.top() + 1;
        ans.pop();
        cout << numV;
        if(!ans.empty()){
            cout << " ";
        }
        else{
            cout << endl;
        }
    }

    return 0;
}