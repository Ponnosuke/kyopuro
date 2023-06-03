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
    i64 N;
    cin >> N;

    if(N <= 1000 - 1){
        cout << N << endl;
    }
    else{
        string str = to_string(N);
        int digCnt = str.size();

        digCnt -= 3;
        for(int rep = 0; rep < digCnt; rep++){
            N /= 10;
        }
        for(int rep = 0; rep < digCnt; rep++){
            N *= 10;
        }

        cout << N << endl;
    }
}