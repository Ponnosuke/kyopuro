/*
    WA
    Line: 42  O(10^6 * 10^6)
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
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N, M;
    cin >> N >> M;

    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<i64> num;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            i64 tmp = A.at(i) * A.at(i) + A.at(j) * A.at(j);
            num.push_back(tmp);
        }
    }

    bool OK = false;
    i64 numSize = num.size();
    for(int i = 0; i < numSize; i++){
        for(int j = 0; j < numSize; j++){
            if(num.at(i) + num.at(j) == M){
                OK = true;
                break;
            }
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}