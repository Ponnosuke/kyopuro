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

const string TABLE = "abcdefgh";

int main() {
    int x, y;
    bool stop = false;
    for(int i = 8; i >= 1; i--){
        for(int j = 0; j < 8; j++){
            char ch;
            cin >> ch;
            if(ch == '*'){
                y = i;
                x = j;
            }
        }
    }

    debugV(x);
    debugVL(y);

    string ans = TABLE.at(x) + to_string(y);

    cout << ans << endl;
}