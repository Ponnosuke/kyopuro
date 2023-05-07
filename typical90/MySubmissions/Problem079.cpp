#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 H, W;
    cin >> H >> W;
    vector<vector<i64>> A(H, vector<i64>(W));
    for(i64 i = 0; i < H; i++){
        for(i64 j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }
    vector<vector<i64>> B(H, vector<i64>(W));
    for(i64 i = 0; i < H; i++){
        for(i64 j = 0; j < W; j++){
            cin >> B.at(i).at(j);
        }
    }

    i64 cnt = 0;
    for(i64 i = 0; i < H-1; i++){
        for(i64 j = 0; j < W-1; j++){
            i64 diff = B.at(i).at(j) - A.at(i).at(j);
            A.at(i).at(j) += diff;
            A.at(i+1).at(j) += diff;
            A.at(i).at(j+1) += diff;
            A.at(i+1).at(j+1) += diff;

            cnt += abs(diff);
        }
    }

    if(A == B){
        cout << "Yes" << endl;
        cout << cnt << endl;
    }
    else{
        cout << "No" << endl;
    }


    // bool OK = true;
    // for(int i = 0; i < H; i++){
    //     if(i < H-1){
    //         if(A.at(i).at(W-1) != B.at(i).at(W-1)){
    //             OK = false;
    //             break;
    //         }
    //     }
    //     else{
    //         for(int j = 0; j < W; j++){
    //             if(A.at(i).at(j) != B.at(i).at(j)){
    //                 OK = false;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // if(OK){
    //     cout << "Yes" << '\n';
    //     cout << cnt << '\n';
    // }
    // else{
    //     cout << "No" << '\n';
    // }

    return 0;
}