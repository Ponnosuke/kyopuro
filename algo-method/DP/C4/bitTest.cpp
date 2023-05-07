/*
    
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    cout << (22 & (1 << 0)) << endl;
    cout << (22 & (1 << 1)) << endl;
    cout << (22 & (1 << 2)) << endl;
    cout << (22 & (1 << 3)) << endl;
    cout << (22 & (1 << 4)) << endl;

    cout << '\n';

    cout << (22 >> 0) << endl;
    cout << (22 >> 1) << endl;
    cout << (22 >> 2) << endl;
    cout << (22 >> 3) << endl;
    cout << (22 >> 4) << endl;

    cout << '\n';

    cout << ((22 >> 0) & 1) << endl;
    cout << ((22 >> 1) & 1) << endl;
    cout << ((22 >> 2) & 1) << endl;
    cout << ((22 >> 3) & 1) << endl;
    cout << ((22 >> 4) & 1) << endl;
}

/*
    OUTPUT:

    0
    2
    4
    0
    16

    22
    11
    5
    2
    1

    0
    1
    1
    0
    1
*/