#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

string S(int n){
    if(n == 1){
        return "1";
    }

    return S(n-1) + " " + to_string(n) + " " + S(n-1);
}

int main() {
    int N;
    cin >> N;
    string ans;
    ans = S(N);

    cout << ans << "\n";
}