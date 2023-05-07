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
    vector<int> x(3), y(3);
    for(int i = 0; i < 3; i++){
        cin >> x.at(i) >> y.at(i);
    }

    int ansx = 0, ansy = 0;
    if(x.at(0) == x.at(1)){
        ansx = x.at(2);
    }
    else if(x.at(1) == x.at(2)){
        ansx = x.at(0);
    }
    else{
        ansx = x.at(1);
    }
    if(y.at(0) == y.at(1)){
        ansy = y.at(2);
    }
    else if(y.at(1) == y.at(2)){
        ansy = y.at(0);
    }
    else{
        ansy = y.at(1);
    }

    cout << ansx << " " << ansy << endl;
}