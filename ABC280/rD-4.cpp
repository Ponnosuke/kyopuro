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

// N! が 素数 p で何回割り切れるかを返す
// つまり n! を素因数分解したとき p は何乗になるか
i64 LegendreFunc(i64 n, i64 p){
    i64 ret = 0;
    while(n > 0){
        ret += (n / p);
        n /= p;
    }

    return ret;
}

// N! が K の倍数か否か
bool isOK(i64 N, map<i64, i64> &factK){

    debugVL(N);

    // debugP();

    bool OK = true;
    for(auto [num, cntK] : factK){
        i64 cntN = LegendreFunc(N, num);
        debugV(num);
        debugV(cntN);
        debugVL(cntK);
        if(cntN < cntK){
            OK = false;
            break;
        }
    }

    // debugP();

    return OK;
}

int main() {
    i64 K;
    cin >> K;

    i64 NG = 1, OK = K;

    // debugP();

    map<i64, i64> factK;
    for(i64 i = 2; i*i <= K; i++){
        i64 cnt = 0;
        while(K % i == 0){
            K /= i;
            cnt++;
        }

        if(cnt > 0){
            factK[i] = cnt;
            debugV(i);
            debugV(cnt);
            debugVL(K);
        }
    }
    if(K != 1){
        factK[K] = 1;
    }

    while(abs(OK - NG) > 1){

        // debugP();

        i64 mid = NG + (OK - NG)/2;

        debugV(OK);
        debugV(NG);
        debugVL(mid);

        if(isOK(mid, factK)){
            debugWL(isOK);
            OK = mid;
        }
        else{
            debugWL(isNG);
            NG = mid;
        }

        debugWL();
    }

    // debugP();

    cout << OK << '\n';
}