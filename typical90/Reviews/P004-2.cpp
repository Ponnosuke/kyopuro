#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<i64>> A(H, vector<i64>(W, 0));
    vector<i64> rowSum(H, 0), clmSum(W, 0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int tmp;
            cin >> tmp;
            A.at(i).at(j) = tmp;
            rowSum.at(i) += tmp;
            clmSum.at(j) += tmp;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << rowSum.at(i) + clmSum.at(j) - A.at(i).at(j);
            
            if(j < W-1){
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}