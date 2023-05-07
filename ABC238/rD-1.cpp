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
    int T;
    cin >> T;

    while(T--){
        i64 a, s;
        cin >> a >> s;

        i64 b = s - 2*a;

        debugV(a);
        debugVL(b);
        bitset<4> bit_a(a), bit_b(b);
        debugV(bit_a);
        debugVL(bit_b);

        debugVL((a&b));
        debugVL((bit_a & bit_b));

        if(b < 0){
            cout << "No" << '\n';
        }
        else if((a & b) == 0){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }

    return 0;
}