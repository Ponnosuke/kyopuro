#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, M;
    cin >> N >> M;

    vector<i64> di, dj;
    for(int i = 0; i * i <= M; i++){
        for(int j = 0; j * j <= M; j++){
            if((i*i + j*j) == M){
                di.push_back(i);
                dj.push_back(j);
                
                di.push_back(-i);
                dj.push_back(j);
 
                di.push_back(i);
                dj.push_back(-j);
 
                di.push_back(-i);
                dj.push_back(-j);
            }
        }
    }

    vector<vector<i64>> field(N, vector<i64>(N, -1));
    field.at(0).at(0) = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    while(!Q.empty()){
        pair<int, int> v = Q.front();
        int ri = v.first, cj = v.second;
        Q.pop();

        for(int i = 0; i < di.size(); i++){
            int ni = ri + di.at(i), nj = cj + dj.at(i);

            if((ni < 0) || (nj < 0) || (ni >= N) || (nj >= N)){
                continue;
            }
            if(field.at(ni).at(nj) != -1){
                continue;
            }

            field.at(ni).at(nj) = field.at(ri).at(cj) + 1;
            Q.push(make_pair(ni, nj));
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << field.at(i).at(j);
            if(j < (N-1)){
                cout << " ";
            }
        }
        cout << '\n';
    }
}