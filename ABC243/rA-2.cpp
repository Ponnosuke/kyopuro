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
    int V, A, B, C;
    cin >> V >> A >> B >> C;

    V %= (A+B+C);

    if(V < A){
        cout << 'F' << endl;
    }
    else if(V < A+B){
        cout << 'M' << endl;
    }
    else{
        cout << 'T' << endl;
    }

    return 0;
}