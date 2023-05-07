/*
    A - +3 +5 +7 
    https://atcoder.jp/contests/arc158/tasks/arc158_a 

    WA
    
    x1 = x2 = x3 = 10^9 のとき、Line:34 の sum がオーバーフロー (2*10^9 + 10^9)
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
    int T;
    cin >> T;

    while(T--){
        vector<int> x(3, 0);
        int sum = 0;
        for(int i = 0; i < 3; i++){
            cin >> x.at(i);
            sum += x.at(i);
        }

        if(sum % 3 != 0){
            cout << -1 << '\n';
            continue;
        }

        int target = sum / 3;
        bool OK = true;
        vector<int> cor(3, 0);
        for(int i = 0; i < 3; i++){
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