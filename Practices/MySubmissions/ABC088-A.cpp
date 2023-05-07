#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, A;
    cin >> N >> A;

    N -= 500*(N/500);

    if(N <= A){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
}