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

const int NUM = 100;

int main() {
    vector<bool> isFace(NUM + 1, true);
    const vector<int> target = {2, 3, 5};
    for(int i = 0; i < 3; i++){
        int a = target.at(i);
        for(int j = a*2; j <= NUM; j += a){
            isFace.at(j) = false;
        }
    }

    vector<bool> isPrime(NUM + 1, true);
    isPrime.at(0) = isPrime.at(1) = false;
    for(int i = 2; i * i <= NUM; i++){
        if(!isPrime.at(i)){
            continue;
        }

        for(int j = i*2; j <= NUM; j += i){
            isPrime.at(j) = false;
        }
    }

    int cnt = 0;
    for(int i = 2; i <= NUM; i++){
        if(!isPrime.at(i) && isFace.at(i)){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}