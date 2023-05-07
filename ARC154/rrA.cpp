#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

using mint = atcoder::modint998244353;

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
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    for(int i = 0; i < N; i++){
        int numA = A.at(i) - '0', numB = B.at(i) - '0';

        if(numA > numB){
            swap(A.at(i), B.at(i));
        }
    }

    mint numA = mint::raw(0), numB = mint::raw(0);
    for(int i = 0; i < N; i++){
        numA *= 10;
        numB *= 10;

        numA += (i64)(A.at(i) - '0');
        numB += (i64)(B.at(i) - '0');
    }

    mint ans = numA*numB;

    cout << ans.val() << endl;
}