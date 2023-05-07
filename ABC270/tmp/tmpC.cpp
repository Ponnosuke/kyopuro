// This is WA.

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<int>> tree(N+1);
    for(int i = 0; i < N; i++){
        int u, v;
        cin >> u >> v;
        tree.at(u).push_back(v);
        tree.at(v).push_back(u);
    }

    vector<bool> visited(N+1, false);
    queue<int> que;
    stack<int> ansStack;

    visited.at(X) = true;
    que.push(X);
    ansStack.push(X);

    bool flag = false;
    while(!que.empty()){
        int v = que.front();

        // debug
        // cout << "v = " << v << endl;

        que.pop();

        for(int nv : tree.at(v)){
            if(tree.at(nv).size() == 1){
                continue;
            }

            ansStack.push(nv);
            if(nv == Y){
                flag = true;
                break;
            }

            if(visited.at(nv)){
                ansStack.pop();
                continue;
            }

            visited.at(nv) = true;
            que.push(nv);
        }

        if(flag)  break;
    }

    // debug
    // while(!ansStack.empty()){
    //     cout << ansStack.top();
    //     ansStack.pop();
    // }

    vector<int> ans(ansStack.size(), -100);
    for(int i = ansStack.size() - 1; i >= 0; i--){
        ans.at(i) = ansStack.top();
        ansStack.pop();
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i);

        if(i >= ans.size() - 1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
}