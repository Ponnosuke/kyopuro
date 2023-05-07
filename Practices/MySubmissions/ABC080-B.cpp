#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int sum = 0, tmp = N;
    while(true){
        sum += tmp % 10;
        tmp /= 10;
        if(tmp == 0) break;
    }

    cout << (N % sum == 0 ? "Yes" : "No" ) << endl;
}