/*
    バグってる
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int getIndex(int i, int j){
    return i*3 + j;
}
pair<int, int> getPos(int n){
    return make_pair(n/3, n%3);
}

void dfs(int idx, int &ans, vector<int> &field, int now, vector<int> &h, vector<int> &w){
    debugVL(idx);
    if(idx == 2){
        if(field.at(0) + field.at(1) >= h.at(0)){
            return;
        }
        else{
            field.at(2) = h.at(0) - field.at(0) - field.at(1);
            for(int i = 1; i <= 28; i++){
                dfs(idx + 1, ans, field, i, h, w);
            }
        }

        return;
    }
    if(idx == 5){
        if(field.at(3) + field.at(4) >= h.at(1)){
            return;
        }
        else{
            field.at(5) = h.at(1) - field.at(3) - field.at(4);
        }

        if(field.at(0) + field.at(3) >= w.at(0)){
            return;
        }
        else{
            field.at(6) = w.at(0) - field.at(0) - field.at(3);
        }

        if(field.at(1) + field.at(4) >= w.at(1)){
            return;
        }
        else{
            field.at(7) = w.at(1) - field.at(1) - field.at(4);
        }

        int check1 = h.at(2) - field.at(6) - field.at(7);
        int check2 = w.at(2) - field.at(2) - field.at(5);
        if(check1 < 1 || check2 < 1){
            return;
        }
        if(check1 == check2){
            ans++;
            return;
        }

        return;
    }

    debugP();

    field.at(idx) = now;
    for(int i = 1; i <= 28; i++){
        dfs(idx + 1, ans, field, i, h, w);
    }

    return;
}

int main() {
    // debug
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         int idx = getIndex(i, j);
    //         debug(getPos(idx).first);
    //         debug(getPos(idx).second);
    //     }
    //     debugWL();
    // }

    vector<int> h(3, 0), w(3, 0);
    for(int i = 0; i < 3; i++){
        cin >> h.at(i);
    }
    for(int j = 0; j < 3; j++){
        cin >> w.at(j);
    }

    vector<int> field(9, 0);
    int ans = 0;
    for(int i = 1; i <= 28; i++){
        dfs(0, ans, field, i, h, w);
    }

    cout << ans << '\n';
}