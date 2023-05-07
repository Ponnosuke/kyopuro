#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int tDist = 0, aDist = 0;
    tDist = (B * A ) * (X / (A + C)) + B * (min(A, X % (A + C)));
    aDist = (E * D) * (X / (D + F)) + E * (min(D, X % (D + F)));

    if(tDist > aDist)  cout << "Takahashi" << endl;
    else if(tDist < aDist)  cout << "Aoki" << endl;
    else  cout << "Draw" << endl;

    return 0;
}