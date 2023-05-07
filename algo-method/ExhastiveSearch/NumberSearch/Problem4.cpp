#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 1;
    for(int i = 1; i <= max(A, B) ; i++){
        if(A % i == 0 && B % i == 0) ans = i;
    }

    cout << ans << endl;
}