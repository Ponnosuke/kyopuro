#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, X, Y;
    cin >> N >> X >> Y;

    i64 red = 1, blue = 0;
    for(int i = 0; i < N-1; i++){
        blue += red*X;
        red += blue;
        blue *= Y;

        // debug
        /*
        cout << "level: " << N - i << endl;
        cout << "(red, blue) = " << red << ", " << blue << endl;
        */
    }

    cout << blue << endl;
}