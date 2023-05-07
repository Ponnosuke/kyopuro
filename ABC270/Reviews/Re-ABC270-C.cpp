#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

vector<vector<int>> tree(200020);
vector<bool> visited(200020, false);
deque<int> deq;
bool stop = false;

void dfs(int nowV, int endV){
    if(!stop){
        deq.push_back(nowV);
    }

    visited.at(nowV) = true;

    if(nowV == endV){
        stop = true;
    }

    if(!stop){
        for(auto nextV : tree.at(nowV)){
            if(!visited.at(nextV)){
                dfs(nextV, endV);
            }
        }
    }

    if(!stop){
        deq.pop_back();
    }

    return;
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;


    
    int u, v;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        tree.at(u).push_back(v);
        tree.at(v).push_back(u);
    }

    dfs(X, Y);

    while(!deq.empty()){
        int now = deq.front();
        deq.pop_front();

        cout << now;

        if(deq.empty()){
            cout << endl;
        }
        else{
            cout << " ";
        }

    }

    return 0;
}