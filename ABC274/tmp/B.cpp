#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++){
        cin >> C.at(i);
    }

    vector<int> X(W, 0);
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            if(C.at(i).at(j) == '#'){
                X.at(j)++;
            }
        }
    }

    for(int i = 0; i < W; i++){
        cout << X.at(i);
        if(i < W - 1)  cout << " ";
        else  cout << '\n';
    }
}