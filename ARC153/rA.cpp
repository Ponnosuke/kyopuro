#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugL(Y)
    #define debugP(Z)
#endif

int main() {
    i64 N;
    cin >> N;

    i64 num = 0;
    i64 cnt = 0;
    for(i64 a = 1; a <= 9; a++){
        for(i64 b = 0; b <= 9; b++){
            for(i64 c = 0; c <= 9; c++){
                for(i64 d = 0; d <= 9; d++){
                    for(i64 e = 0; e <= 9; e++){
                        for(i64 f = 0; f <= 9; f++){
                            cnt++;
                            num = a*110000000LL + b*1000000 + c*100000 + d*11000 + e*101 + f*10;

                            if(cnt >= N){
                                goto OUT;
                            }
                        }
                    }
                }
            }
        }
    }

    OUT:
    cout << num << '\n';
}