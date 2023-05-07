#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

const int SIZE = 100001;

int main() {
    i64 N;
    cin >> N;
    vector<i64> cnt(SIZE, 0);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        cnt.at(A)++;
    }

    i64 nume = 0, deno = (N * (N-1) ) / 2;
    for(int i = 0; i < SIZE; i++){
        i64 tmp = cnt.at(i);
        nume += (tmp * (tmp - 1)) / 2;
    }

    if(nume == 0){
        cout << 0 << '\n';
    }
    else if(nume == deno){
        cout << 1 << '\n';
    }
    else{
        double up = nume, down = deno;
        cout << fixed << setprecision(18);
        cout << up / down << '\n';
    }
}