#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

vector<int> dH = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> dW = {1, 1, 0, -1, -1, -1, 0 ,1};

const int BITSIZE = 18;

int solver1(int H, int W){
    if(H % 2 != 0)  H++;
    if(W % 2 != 0)  W++;

    return (H / 2) * (W / 2);
}

// 愚直解
int solver2(int H, int W){
    i64 N = H * W;
    if(N > BITSIZE){
        cerr << "Dekai" << "\n";
        return -3389;
    }

    vector<vector<int>> field(H, vector<int>(W, 0)); // 1:on,  0:off
    int ans = -1;

    // debug
    // cerr << "point31" << endl;

    for(i64 tmp = 0; tmp < ((i64)1 << BITSIZE); tmp++){
        bitset<BITSIZE> bs(tmp);

        // debug
        // cerr << "point37" << endl;

        int sum = 0;
        for(int i = 0; i < N; i++){

            // debug
            // cerr << "i = " << i << endl;

            if(bs.test(i)){
                sum++;

                // debug
                // cerr << "point45" << endl;

                field.at(i / W).at(i % W) = 1;

                // debug
                // cerr << "point50" << endl;
            }
            else{

                // debug
                // cerr << "point55" << endl;

                field.at(i / W).at(i % W) = 0;

                // debug
                // cerr << "point60" << endl;
            }

            // debug
            // cerr << "\n";
        }

        // debug
        // cerr << "point51" << endl;

        bool OK = true;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(field.at(i).at(j) == 1){
                    for(int k = 0; k < 8; k++){
                        int ni = i + dH.at(k), nj = j + dW.at(k);
                        if(ni < 0 || H <= ni || nj < 0 || W <= nj){
                            continue;
                        }

                        if(field.at(ni).at(nj) == 1){
                            OK = false;
                            break;
                        }
                    }
                }
            }
        }

        // debug
        // // cerr << "pointB" << endl;

        if(OK){
            ans = max(ans, sum);
        }
    }

    return ans;
}

// int乱数ジェネレーター
// [L, R] を満たす int 型のランダムな整数を返す
// ただし、mt19937 は uint32_t 型を返していることに注意
int myRnd32(int L, int R){
    random_device seedGen;
    mt19937 rd(seedGen());

    int ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}

int main() {
    for(int i = 0; i < 50; i++){
        int H = 100, W = 100;
        while(H * W > BITSIZE){
            H = myRnd32(1, 100);
            W = myRnd32(1, 100);
        }

        int result2 = solver2(H, W);
        int result1 = solver1(H, W);
        bool boo = (result1 == result2);
        if(!boo){
            cout << "Wrong!" << endl;
            cout << "(H, W) = " << H << " " << W << endl;
            cout << "solver1(H, W) = " << result1 << endl;
            cout << "solver2(H, W) = " << result2 << endl;
            break;
        }
    }

    cerr << "finished!" << endl;

    return 0;
}



// int main() {
//     int H, W;
//     cin >> H >> W;

//     int result2 = solver2(H, W);
//     cerr << result2 << endl;

//     int result1 = solver1(H, W);
//     cerr << result1 << endl;

//     bool boo = (result1 == result2);
//     if(!boo){
//         cout << "Wrong!" << endl;
//         cout << "(H, W) = " << H << " " << W << endl;
//         cout << "solver1(H, W) = " << result1 << endl;
//         cout << "solver2(H, W) = " << result2 << endl;
//     }
//     else{
//         cout << "Correct!" << endl;
//     }

//     return 0;
// }