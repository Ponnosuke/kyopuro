#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &x:A) cin >> x;

    int ans = 0;
    for(auto x:A){
        if(x == 1) continue;
        
        bool isPrime = true;
        for(int i = 2; i < x; i++){
            if(x % i == 0)  isPrime = false;
        }

        if(isPrime) ans++;
    }

    cout << ans << endl;
}