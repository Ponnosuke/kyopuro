/*
    C - GCD on Blackboard 
    https://atcoder.jp/contests/abc125/tasks/abc125_c 

    右からと左からの累積和的な考えを使う方法
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
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> L(N, 0);
    L.at(0) = A.at(0);
    for(int i = 1; i < N; i++){
        L.at(i) = gcd(L.at(i-1), A.at(i));
    }
    vector<int> R(N, 0);
    R.at(N-1) = A.at(N-1);
    for(int i = N-2; i >= 0; i--){
        R.at(i) = gcd(R.at(i+1), A.at(i));
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            ans = max(ans, R.at(1));
        }
        else if(i == N-1){
            ans = max(ans, L.at(N-2));
        }
        else{
            int G = gcd(L.at(i-1), R.at(i+1));
            ans = max(ans, G);
        }
    }

    cout << ans << endl;
}