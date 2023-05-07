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
    vector<int> A = {1, 2, 3, 4, 5};
    int idx1 = distance(A.begin(), lower_bound(A.begin(), A.end(), 7));
    cout << idx1 << '\n'; // 5
    int idx2 = distance(A.begin(), lower_bound(A.begin(), A.end(), 0));
    cout << idx2 << '\n'; // 0
    int idx3 = distance(A.begin(), lower_bound(A.begin(), A.end(), 1));
    cout << idx3 << '\n'; // 0
}