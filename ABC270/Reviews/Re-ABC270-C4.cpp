#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

map<int, int> rec;
vector<vector<int>> tree(200010);

void dfs(int nowV, int prevV){
    for(int nxV : tree.at(nowV)){
        if(nxV == prevV){
            continue;
        }
        rec[nxV] = nowV;
        dfs(nxV, nowV);
    }

    return;
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree.at(u).push_back(v);
        tree.at(v).push_back(u);
    }

    dfs(X, -1);

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