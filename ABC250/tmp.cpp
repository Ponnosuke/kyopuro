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


// 平方根が 1 ~ 4294967296 (4 * 10^9 くらい) の範囲に収まる、平方数の平方根を
//　二分探索して返す関数
// 渡すものは平方数であることに注意
// 平方根を知りたい平方数を渡す
// OK の部分は上限を見積もって臨機応変に (1LL << 32 だとオーバーフローしないか怖い)
/*
    引数 N が平方数でない時に返す値:

    return ceil(sqrt(N));

    sqrt() は組み込み関数のもの。double を返すやつ

    というか 非負整数 N に対して 返す値が ceil(sqrt(N));
*/
i64 ceilSqrt(i64 n2){

    assert(n2 >= 0);

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
/*
    与えられた非負整数 N に対して
    ceil(sqrt(N)) を返す。

    sqrt() は組み込み関数のもの。double を返すやつ。
*/
i64 ceilRt3(i64 n2, i64 upperBound){

    assert(n2 >= 0);

    i64 NG = -1, OK = upperBound;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n2 <= mid*mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }

        debugV(OK);
        debugVL(NG);
    }

    return OK;
}

i64 floorRt3(i64 n, i64 upperBound){
    
    assert(n >= 0);
    
    i64 NG = -1, OK = upperBound;
    while(abs(OK - NG) > 1){
        i64 mid = OK + (NG - OK)/2;
        if(n <= mid*mid*mid){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    if(OK*OK*OK > n){
        OK--;
    }

    return OK;
}

const i64 INF = (1LL << 31);

int main() {
    cout << fixed << setprecision(15);

    i64 N;
    cin >> N;
    i64 num2 = ceilRt3(N, 1000000);
    i64 num3 = floorRt3(N, 1000000);
    cout << "ceilRt3(" << N << ", " << INF << ") = " << num2 << '\n';
    cout << "floorRt3(" << N << ", " << INF << ") = " << num3 << '\n';
    cout << "cbrt(" << N << ") = " << cbrt((double)N) << '\n';
    cout << num2 << " ^ 3 " << " = " << num2*num2*num2 << '\n';
    cout << num3 << " ^ 3 " << " = " << num3*num3*num3 << '\n';

    cout << '\n';
    cout << "1LL << 31 = " << (1LL << 31) << '\n';
    cout << "1LL << 32 = " << (1LL << 32) << '\n';

    return 0;
}