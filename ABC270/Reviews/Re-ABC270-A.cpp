#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B;
    cin >> A >> B;
    bitset<3> bitA(A), bitB(B);
    
    cout << (bitA | bitB).to_ullong() << endl;
}