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

// i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

return ret;
}

int main() {
    int N = myRnd64(1, 10);

    string S = "", T = "";
    for(int i = 0; i < N; i++){
        int rS = myRnd64(0, 50), rT = myRnd64(0, 50);
        if(rS < 26){
            S += (char)('a' + rS);
        }
        else{
            S += '@';
        }

        if(rT < 26){
            T += (char)('a' + rT);
        }
        else{
            T += '@';
        }
    }

    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    cout << S << '\n';
    cout << T << endl;

    return 0;
}