#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif


// 平方根が 1 ~ 4294967296 (4 * 10^9 くらい) の範囲に収まる、平方数の平方根を
//　二分探索して返す関数
// 渡すものは平方数であることに注意
// 平方根を知りたい平方数を渡す
// OK の部分は上限を見積もって臨機応変に (1LL << 32 だとオーバーフローしないか怖い)
i64 mySqrt(i64 n2){
    i64 NG = -1, OK = (1LL << 32);
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n2 <= mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    return OK;
}

// 最初に上界を与えるようにしたバージョン
i64 mySqrt2(i64 n2, i64 jokai){
    i64 NG = -1, OK = jokai;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n2 <= mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    return OK;
}

const i64 INF = (1LL << 31);

int main() {
    i64 N;
    cin >> N;
    i64 num = mySqrt(N);
    i64 num2 = mySqrt2(N, INF);
    cout << num << '\n';

    cout << '\n';
    cout << "1LL << 31 = " << (1LL << 31) << '\n';
    cout << "1LL << 32 = " << (1LL << 32) << '\n';

    return 0;
}