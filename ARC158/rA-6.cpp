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
        vector<i64> x(3, 0);
        i64 sum = 0;
        for(int i = 0; i < 3; i++){
            cin >> x.at(i);
            sum += x.at(i);
        }

        if(sum % 3 != 0){
            cout << -1 << '\n';
            continue;
        }

        i64 target = sum / 3;
        vector<i64> diff(3, 0);
        bool OK = true;
        for(int i = 0; i < 3; i++){
            diff.at(i) = abs(x.at(i) - target);
            if(diff.at(i) % 2 != 0){
                OK = false;
                break;
            }
        }
        if(!OK){
            cout << -1 << '\n';
            continue;
        }

        i64 ans = 0;
        for(int i = 0; i < 3; i++){
            ans += diff.at(i);
        }
        ans /= 4;

        cout << ans << '\n';
    }

    return 0;
}