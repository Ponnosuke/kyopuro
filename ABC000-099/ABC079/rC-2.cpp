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
    vector<int> num(4, 0);
    for(int i = 0; i < 4; i++){
        char ch;
        cin >> ch;
        num.at(i) = (int)(ch - '0');
    }

    int op = 0;
    for(int mask = 0; mask < (1 << 3); mask++){
        int now = num.at(0);
        for(int i = 0; i < 3; i++){
            if((mask >> i) & 1){
                now += num.at(i+1);
            }
            else{
                now -= num.at(i+1);
            }
        }
        if(now == 7){
            op = mask;
            break;
        }
    }

    cout << num.at(0);
    for(int i = 0; i < 3; i++){
        if((op >> i) & 1){
            cout << '+';
        }
        else{
            cout << '-';
        }
        cout << num.at(i+1);
    }

    cout << "=7" << endl;
}