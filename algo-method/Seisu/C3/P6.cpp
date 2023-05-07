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

    i64 num = abs(A - B);

    i64 cnt = 0;
    for(i64 i = 1; i*i <= num; i++){
        if(num % i != 0){
            continue;
        }

        if(A % i == B % i){
            cnt++;
        }

        if(i != num/i){
            i64 d = num/i;

            if(A % d == B % d){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}