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

const string INI_STR = "ABCDEF";

int main() {
    string str = INI_STR;

    cout << str << '\n';  // ABCDEF

    debugVL(*prev(str.end(), 1));  // F

    rotate(str.begin(), prev(str.end(), 1), str.end());
    // 文字の先頭、区切る位置、文字の最後

    //  ABCDEF
    //  ABCDE F
    //  F ABCDE
    //  FABCDE

    cout << str << '\n';  //  FABCDE
    cout << '\n';

    str = INI_STR;

    cout << str << '\n';  // ABCDEF

    debugVL(*next(str.begin(), 3));  // D
    debugVL(*prev(str.end(), 2));  // E

    rotate(next(str.begin(), 3), prev(str.end(), 1), str.end());

    //  ABCDEF
    //  DEF
    //  DE  F
    //  F  DE
    //  FDE
    //  ABCFDE


    cout << str << '\n';  // ABCFDE
    cout << '\n';

    str = INI_STR;

    cout << str << '\n';  //  ABCDEF

    rotate(str.begin(), next(str.begin(), 1), next(str.begin(), 2));

    cout << str << '\n';  //  BACDEF

    return 0;
}