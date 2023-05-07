#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> G.at(i).at(j);
        }
    }

    vector<vector<int>> seenTable(H, vector<int>(W, 0));  // 1:seen  0: haven't
    seenTable.at(0).at(0) = 1;

    int index = 0, jndex = 0;
    bool isLoop = false;
    while(true){
        if(G.at(index).at(jndex) == 'U') index--;
        else if(G.at(index).at(jndex) == 'D') index++;
        else if(G.at(index).at(jndex) == 'L') jndex--;
        else  jndex++;  // R

        if(index < 0){
            index = 0;
            break;
        }
        if(index > H-1){
            index = H-1;
            break;
        }
        if(jndex < 0){
            jndex = 0;
            break;
        }
        if(jndex > W-1){
            jndex = W-1;
            break;
        }

        if(seenTable.at(index).at(jndex) == 1){
            isLoop = true;
            break;
        }
        else{
            seenTable.at(index).at(jndex) = 1;
        }
    }

    index++;
    jndex++;

    if(isLoop){
        cout << -1 << endl;
    }
    else{
        cout << index << " " << jndex << endl;
    }
}