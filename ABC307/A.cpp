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
    vector<int> A(7*N + 1);
    for(int i = 1; i <= 7*N; i++){
        cin >> A.at(i);
    }

    int sum = 0;
    for(int i = 1; i <= 7*N; i++){
        sum += A.at(i);

        if(i % 7 == 0){
            cout << sum << " ";
            sum = 0;
        }
    }
    cout << endl;
}