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
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int upper_num = B+D;
    vector<bool> is_prime(upper_num + 1, true);
    is_prime.at(0) = false;
    is_prime.at(1) = false;
    set<int> primes;
    for(int i = 2; i <= upper_num; i++){
        if(!is_prime.at(i)){
            continue;
        }

        primes.insert(i);

        for(int j = i*i; j <= upper_num; j += i){
            is_prime.at(j) = false;
        }
    }

    bool takahashi_win = false;
    for(int i = A; i <= B; i++){
        bool found = false;
        for(int j = C; j <= D; j++){
            if(primes.count(i + j)){
                found = true;
                break;
            }
        }

        if(!found){
            takahashi_win = true;
            break;
        }
    }

    if(takahashi_win){
        cout << "Takahashi" << '\n';
    }
    else{
        cout << "Aoki" << '\n';
    }

    return 0;
}