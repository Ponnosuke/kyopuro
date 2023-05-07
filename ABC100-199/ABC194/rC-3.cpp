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
    vector<i64> cnt(401, 0);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        A += 200;

        cnt.at(A)++;
    }

    i64 sum = 0;
    for(i64 i = 0; i <= 400; i++){
        for(i64 j = 0; j <= 400; j++){
            sum += (i - j)*(i - j)*cnt.at(i)*cnt.at(j);
        }
    }

    sum /= 2;

    cout << sum << '\n';
}