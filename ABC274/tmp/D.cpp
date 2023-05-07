#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int TEN_THOU = 10000;
const int FIELD_SIZE = 2 * TEN_THOU + 1;

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    x += TEN_THOU;
    y += TEN_THOU;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<vector<int>> field(FIELD_SIZE, vector<int>(FIELD_SIZE, 0));
    // 1: seen, 2: haven't
    queue<pair<int, int>> Q;
    Q.push(make_pair(TEN_THOU, TEN_THOU));
    field.at(TEN_THOU).at(TEN_THOU) = 1;
    field.at(TEN_THOU + A.at(0)).at(TEN_THOU) = 1;
    int index = 1;
    while(index < N){
        pair<int, int> v = Q.front();
        Q.pop();
        int nowX = v.first, nowY = v.second;
        field.at(nowX).at(nowY) = 1;
        if(index % 2 != 0){  // 上か下
            Q.push(make_pair(nowX, nowY + A.at(index)));
            Q.push(make_pair(nowX, nowY - A.at(index)));
        }
        else{  // 右か左
            Q.push(make_pair(nowX + A.at(index), nowY));
            Q.push(make_pair(nowX - A.at(index), nowY));
        }
    }


}