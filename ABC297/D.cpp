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
    i64 A, B;
    cin >> A >> B;

    debugVL(gcd(A, B));

    i64 G = gcd(A, B);

    i64 cnt = 0;
    while(A != B){
        if(A < B){
            swap(A, B);
        }

        debugV(A);
        debugVL(B);

        if(B == G){
            cnt += (A / B);
            cnt--;
            break;
        }

        cnt += (A / B);
        A %= B;
    }

    cout << cnt << '\n';
}