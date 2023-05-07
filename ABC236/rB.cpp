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
    vector<int> cnt(N, 0);
    for(int i = 0; i < 4*N - 1; i++){
        int A;
        cin >> A;
        A--;
        cnt.at(A)++;
    }

    for(int i = 0; i < N; i++){
        if(cnt.at(i) != 4){
            cout << i+1 << endl;

            return 0;
        }
    }

    return 0;
}