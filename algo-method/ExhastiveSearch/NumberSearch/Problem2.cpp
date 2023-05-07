#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 1 ; i <= N ; i++){
        if(N % i == 0) cnt++;
    }

    cout << cnt << endl;
}