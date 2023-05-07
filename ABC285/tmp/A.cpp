#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugW(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugW(Z)
#endif

int main() {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    vector<vector<bool>> tree(15, vector<bool>(15, false));
    for(int i = 1; i <= 7; i++){
        int index = i-1;
        int next1 = i*2 - 1;
        int next2 = i*2;
        tree.at(index).at(next1) = true;
        tree.at(index).at(next2) = true;
        tree.at(next1).at(index) = true;
        tree.at(next2).at(index) = true;
    }

    bool OK = tree.at(a).at(b);
    cout << (OK ? "Yes" : "No") << '\n';

}