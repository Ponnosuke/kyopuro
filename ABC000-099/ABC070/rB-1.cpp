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

    vector<int> time(110, 0);
    time.at(A)++;
    time.at(B)--;
    time.at(C)++;
    time.at(D)--;

    int ans = 0;
    for(int i = 0; i <= 100; i++){
        if(time.at(i) >= 2){
            ans++;
        }

        time.at(i+1) += time.at(i);
    }

    cout << ans << endl;

    return 0;
}