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

const int SIZE = 500001;

int main() {
    int N;
    cin >> N;
    vector<int> cnt(SIZE, 0);
    int ic = N;
    for(;ic--;){
        int A;
        cin >> A;
        cnt.at(A)++;
    }

    int mxCnt = -1, mxIdx = 0;
    for(int i = 0; i < SIZE; i++){
        if(mxCnt < cnt.at(i)){
            mxCnt = cnt.at(i);
            mxIdx = i;
        }
    }

    cout << mxIdx << '\n';
}