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

vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    set<pair<int, int>> st1, st2;
    for(int i = 0; i < 8; i++){
        st1.insert(make_pair(x1 + dx.at(i), y1 + dy.at(i)));
        st2.insert(make_pair(x2 + dx.at(i), y2 + dy.at(i)));
    }

    bool OK = false;
    for(auto &ele : st1){
        if(st2.count(ele)){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}