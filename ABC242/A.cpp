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
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    cout << fixed << setprecision(20);
    if(X <= A){
        cout << 1 << endl;
    }
    else if(X > B){
        cout << 0 << endl;
    }
    else{
        cout << (double)C / (double)(B - A) << endl;
    }

    return 0;
}