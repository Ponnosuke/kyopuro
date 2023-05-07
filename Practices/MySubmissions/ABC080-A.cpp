#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int sum1 = A * N, sum2 = B;

    cout << min(sum1, sum2) << endl;
}