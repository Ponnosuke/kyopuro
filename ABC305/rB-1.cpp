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
    char p, q;
    cin >> p >> q;

    vector<int> dist = {0, 3, 1, 4, 1, 5, 9};
    for(int i = 0; i < 6; i++){
        dist.at(i+1) += dist.at(i);
    }

    cout << abs(dist.at(p - 'A') - dist.at(q - 'A')) << endl;
}