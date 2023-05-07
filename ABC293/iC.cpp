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

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const i64 MIN = 1LL;
const i64 MAX = 1000000000LL;

int main() {
    int H = 10, W = 10;
    cout << H << " " << W << '\n';
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << myRnd64(1, 10);

            if(j < W-1){
                cout << " ";
            }
        }
        cout << '\n';
    }
}