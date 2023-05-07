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
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        if(i % 15 == 0){
            cout << "FizzBuzz";
        }
        else if(i % 3 == 0){
            cout << "Fizz";
        }
        else if(i % 5 == 0){
            cout << "Buzz";
        }
        else{
            cout << i;
        }
        cout << '\n';
    }
}