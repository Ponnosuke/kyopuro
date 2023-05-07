#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const vector<int> dx = {-1, -1, 0, 0, 1, 1};
const vector<int> dy = {-1, 0, -1, 1, 0, 1};

vector<vector<char>> field(2020, vector<char>(2020, 'w'));

void dfs(int x, int y){
    field.at(x).at(y) = 'w';

    for(int i = 0; i < 6; i++){
        int nx = x + dx.at(i), ny = y + dy.at(i);
        if(nx < 0 || nx > 2000 || ny < 0 || ny > 2000)  continue;
        if(field.at(nx).at(ny) == 'w') continue;

        dfs(nx, ny);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++){
        cin >> X.at(i) >> Y.at(i);
        X.at(i) += 1000;
        Y.at(i) += 1000;
    }

    for(int i = 0; i < N; i++){
        field.at(X.at(i)).at(Y.at(i)) = 'b';
    }

    int ans = 0;
    for(int i = 0; i < 2005; i++){
        for(int j = 0; j < 2005; j++){
            if(field.at(i).at(j) == 'b'){
                ans++;

                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}