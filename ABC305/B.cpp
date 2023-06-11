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
    map<char, int> mp;
    mp['A'] = 0;
    mp['B'] = mp['A'] + 3;
    mp['C'] = mp['B'] + 1;
    mp['D'] =  mp['C'] + 4;
    mp['E'] = mp['D'] + 1;
    mp['F'] = mp['E'] + 5;
    mp['G'] = mp['F'] + 9;

    char p, q;
    cin >> p >> q;

    cout << abs(mp[p] - mp[q]) << endl;
}