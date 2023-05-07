#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int TEN_THOU = 10000;
const int FIELD_SIZE = 2 * TEN_THOU + 1;

vector<vector<int>> field(FIELD_SIZE, vector<int>(FIELD_SIZE, 0));
// 1: OK, 0: NG

void dfs(int x, int y, int index, vector<int> A, int N){
    if(index == N - 1){
        field.at(x).at(y) = 2;
    }
    else{
        if(field.at(x).at(y) != 2)  field.at(x).at(y) = 1;
    }
    index++;

    if(index > (N-1)){
        return;
    }

    if(index % 2 != 0){
        dfs(x, y + A.at(index), index, A, N);
        dfs(x, y - A.at(index), index, A, N);
    }
    else{
        dfs(x + A.at(index), y, index, A, N);
        dfs(x - A.at(index), y, index, A, N);
    }

    return;
}

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    x += TEN_THOU;
    y += TEN_THOU;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    field.at(TEN_THOU).at(TEN_THOU) = 1;
    field.at(TEN_THOU + A.at(0)).at(TEN_THOU) = 1;

    dfs(TEN_THOU + A.at(0), TEN_THOU, 0, A, N);

    bool OK = (field.at(x).at(y) == 2);
    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}