#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    i64 tmp = (i64)pow(2,31);

    if(-tmp <= N && N < tmp)  cout << "Yes";
    else  cout << "No";

    cout << "\n";
}