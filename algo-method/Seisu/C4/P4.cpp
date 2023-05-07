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

int divCnt(int n){
    int ret = 0;

    for(int i = 1; i*i <= n; i++){
        if(n % i != 0){
            continue;
        }

        ret++;
        if(n/i != i){
            ret++;
        }
    }

    return ret;
}

const int POW5 = 100000;

int main() {
    vector<int> ans;
    for(int i = 1; i <= POW5; i++){
        int result = divCnt(i);

        if(result == 6){
            ans.push_back(i);
            if(ans.size() >= 5){
                break;
            }
        }
    }

    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
}