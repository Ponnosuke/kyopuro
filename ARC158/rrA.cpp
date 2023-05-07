/*
    A - +3 +5 +7 
    https://atcoder.jp/contests/arc158/tasks/arc158_a 
    
    AC
*/
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
    i64 T;
    cin >> T;

    while(T--){
        vector<i64> x(3, 0);
        i64 sum = 0;
        for(i64 i = 0; i < 3; i++){
            cin >> x.at(i);
            sum += x.at(i);
        }

        if(sum % 3 != 0){
            cout << -1 << '\n';
            continue;
        }

        i64 target = sum / 3;
        bool OK = true;
        vector<i64> cor(3, 0);
        for(i64 i = 0; i < 3; i++){
            cor.at(i) = abs(x.at(i) - target);
            if(cor.at(i) % 2 != 0){
                OK = false;
                break;
            }
            else{
                cor.at(i) /= 2;
            }
        }
        if(!OK){
            cout << -1 << '\n';
            continue;
        }

        sort(cor.begin(), cor.end());
        if(cor.at(0) + cor.at(1) == cor.at(2)){
            cout << cor.at(2) << '\n';
        }
        else{
            cout << cor.at(0) + cor.at(1) + cor.at(2) << '\n';
        }
    }

    return 0;
}