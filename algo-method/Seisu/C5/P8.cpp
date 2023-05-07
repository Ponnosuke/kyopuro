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
    i64 A, B, K;
    cin >> A >> B >> K;

    if(A == K || B == K){
        cout << "Yes" << endl;

        return 0;
    }

    if(A == B){
        cout << "No" << endl;

        return 0;
    }

    if(K > A && K > B){
        cout << "No" << endl;

        return 0;
    }

    if(A < B){
        swap(A, B);
    }

    i64 G = gcd(A, B);

    if((A-K) % G == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}