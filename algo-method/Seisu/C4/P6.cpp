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

i64 mu(i64 n){
    if(n == 1){
        return 1LL;
    }

    bool zero = false;
    i64 k = 0;
    for(i64 i = 2; i*i <= n; i++){
        if(n % i != 0){
            continue;
        }
        i64 cnt = 0;
        while(n % i == 0){
            cnt++;
            if(cnt >= 2){
                zero = true;
                break;
            }
            n /= i;
        }

        k++;
        if(zero){
            break;
        }
    }
    if(n != 1){
        k++;
    }

    debugVL(k);

    if(zero){
        return 0LL;
    }
    else{
        if(k % 2 == 0){
            return 1LL;
        }
        else{
            return -1LL;
        }
    }
}

int main() {
    i64 N;
    cin >> N;
    cout << mu(N) << endl;

    return 0;
}