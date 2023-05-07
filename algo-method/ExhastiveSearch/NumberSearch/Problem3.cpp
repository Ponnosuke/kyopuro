#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    if(N == 1){
        cout << "No" << endl;
        return 0;
    }

    bool isPrime = true;
    for(int i = 2; i*i <= N; i++){
        if(N % i == 0){
            isPrime = false;
            break;
        }
    }

    cout << (isPrime ? "Yes" : "No") << endl;

    return 0;
}