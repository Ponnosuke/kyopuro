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

const i64  G = 12;
const i64  L = 480;

int main() {
    i64 num = G*L;
    vector<i64> ans;
    for(i64 i = 1; i*i <= num; i++){
        if(num % i != 0){
            continue;
        }

        i64 A = i, B = num / i;
        i64 gcdAB = gcd(A, B);
        i64 lcmAB = (A*B)/gcdAB;
        if(gcdAB == G && lcmAB == L){
            ans.push_back(A + B);
        }
    }

    i64 size = ans.size();
    sort(ans.begin(), ans.end());
    for(i64 i = 0; i < size; i++){
        cout << ans.at(i);

        if(i < size - 1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}