#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int f(int k){
    if(k==0)  return 1;
    else return k * f(k-1);
}

int main() {
    int N;
    cin >> N;
    cout << f(N) << endl;
}