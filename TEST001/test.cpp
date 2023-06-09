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

void mySwap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;

    return;
}

int main() {
    int x = 10, y = 20;
    debugV(x);
    debugVL(y);

    debugWL(swap);
    mySwap(x, y);
    debugV(x);
    debugVL(y);
}