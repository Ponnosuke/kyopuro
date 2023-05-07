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
    i64 N, K, X;
    cin >> N >> K >> X;
    vector<i64> A(N, 0);
    i64 sum = 0;
    i64 req = 0;
    for(int i = 0; i < N; i++){
        i64 iA;
        cin >> iA;
        A.at(i) = iA;
        req += (iA / X);
        sum += iA;
    }

    if(req >= K){
        debugP();
        sum -= K*X;
    }
    else{
        i64 rest = K - req;
        if(rest >= N){
            debugP();
            sum = 0;
        }
        else{
            debugP();
            debugV(sum);
            debugVL(req);
            sum -= X*req;
            for(int i = 0; i < N; i++){
                A.at(i) %= X;
            }
            sort(A.begin(), A.end(), greater<i64>());
            for(int i = 0; i < rest; i++){
                sum -= A.at(i);
            }
        }
    }

    cout << sum << '\n';
}