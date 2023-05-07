#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

bool isOK(i64 x, i64 L, i64 k, vector<i64> &A){
    i64 cnt = 0, pre = 0;
    bool OK = false;
    for(auto ele : A){
        if(ele - pre >= x && L - ele >= x){
            cnt++;
            pre = ele;
        }
    }

    if(cnt >= k){
        OK = true;
    }

    return OK;
}

int main() {
    i64 N, L;
    cin >> N >> L;
    i64 K;
    cin >> K;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    i64 OK = 0, NG = L;
    while(abs(OK - NG) > 1){
        i64 mid = NG + (OK - NG)/2;
        if(isOK(mid, L, K, A)){
            OK = mid;
        }
        else{
            NG = mid;
        }
    }

    cout << OK << '\n';

    return 0;
}