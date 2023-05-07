#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// func(n, p)  n! の因数に p が何個含まれるか  (p >= 2)
i64 func(i64 n, i64 p){
  i64 ret = 0;
  while(n){
    ret += n/p;
    n /= p;
  }
  
  return ret;
}

// ここでは、map<i64, i64> は参照渡しにした方が良い。
// bool isOK(i64 n, map<i64, i64> &mp){
bool isOK(i64 n, map<i64, i64> mp){
    bool OK = true;
    for(auto [p, cnt] : mp){
        if(cnt > func(n, p)){
            OK = false;
            break;
        }
    }

    return OK;
}

int main() {
    i64 K;
    cin >> K;

    i64 tmpK = K;
    map<i64, i64> facts;
    for(i64 i = 2; i*i <= tmpK; i++){
        if(tmpK % i != 0){
            continue;
        }

        i64 cnt = 0;
        while(tmpK % i == 0){
            cnt++;
            tmpK /= i;
        }

        facts[i] = cnt;
    }
    if(tmpK != 1){
        facts[tmpK] = 1;
    }

    i64 NG = 1, OK = K;
    while(OK - NG > 1){
        i64 mid = NG + (OK - NG)/2;
        if(isOK(mid, facts)){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    cout << OK << '\n';

    return 0;
}