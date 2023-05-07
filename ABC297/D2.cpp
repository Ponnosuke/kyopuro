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

i64 solver1(i64 A, i64 B){
    i64 cnt = 0;
    while(A != B){
        if(A < B){
            swap(A, B);
        }

        A -= B;
        cnt++;
    }

    return cnt;
}

i64 solver2(i64 A, i64 B){
    // debugVL(gcd(A, B));

    i64 G = gcd(A, B);

    i64 cnt = 0;
    while(A != B){
        if(A < B){
            swap(A, B);
        }

        // debugV(A);
        // debugVL(B);

        if(B == G){
            cnt += (A / B);
            cnt--;
            break;
        }

        cnt += (A / B);
        A %= B;
    }

    return cnt;
}

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const i64 LOOP_CNT = 100;

int main() {
    i64 A, B;

    cout << solver1(A, B) << '\n';
}