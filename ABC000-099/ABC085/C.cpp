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
    i64 N, Y;
    cin >> N >> Y;

    bool OK = false;
    i64 ansX = -1, ansY = -1, ansZ = -1;
    for(i64 i = 0; i <= N; i++){
        for(i64 j = 0; j + i <= N; j++){
            i64 k = N - i - j;
            if(k < 0){
                continue;
            }

            if((10000*i + 5000*j + 1000*k) == Y){
                OK = true;
                ansX = i;
                ansY = j;
                ansZ = k;
                break;
            }
        }

        if(OK){
            break;
        }
    }

    cout << ansX << " " << ansY << " " << ansZ << endl;

    return 0;
}