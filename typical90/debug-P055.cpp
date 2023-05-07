/*
    愚直解
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
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
    // int N;
    // cin >> N;
    // i64 P, Q;
    // cin >> P >> Q;
    // vector<i64> A(N);
    // for(int i = 0; i < N; i++){
    //     cin >> A.at(i);
    // }

    int N = 100;

    /*
    vector<int> comb(N, 1);
    for(int i = 0; i < 5; i++){
        comb.at(i) = 0;
    }

    i64 ans = 0;
    do{
        i64 tmp = 1;
        for(int i = 0; i < N; i++){
            if(comb.at(i) == 0){
                tmp *= (A.at(i) % P);
                tmp %= P;
            }
        }

        if(tmp % P == Q){
            ans++;
        }
    }while(next_permutation(comb.begin(), comb.end()));

    cout << ans << endl;
    */


    i64 cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                for(int l = k + 1; l < N; l++){
                    for(int m = l + 1; m < N; m++){
                        cnt++;
                    }
                }
            }
        }
    }

    cout << "N = " << N << endl;
    cout << "cnt = " << cnt << endl;
}