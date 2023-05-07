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

    while(V >= 0){
        if(V - A < 0){
            cout << 'F' << endl;

            return 0;
        }

        V -= A;
        if(V - B < 0){
            cout << 'M' << endl;

            return 0;
        }

        V -= B;
        if(V - C < 0){
            cout << 'T' << endl;

            return 0;
        }

        V -= C;
    }

    return 0;
}