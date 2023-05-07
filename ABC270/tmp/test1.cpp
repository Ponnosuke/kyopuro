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

    bool flag = false;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        ansStack.push(v);

        for(auto nv : tree.at(v)){

            if(nv == Y){
                flag = true;
                break;
            }
            ansStack.push(nv);
            if(!visited.at(nv)){
                ansStack.pop();
                continue;
            }

            visited.at(nv) = true;
            que.push(nv);
        }

        if(flag)  break;
    }

    while(!ansStack.empty()){
        cout << ansStack.top();
        ansStack.pop();
    }

    cout << endl;
}