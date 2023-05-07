#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int k;
    cin >> k;

    string str = "3,1,4,1,5,9,2,6,5,3";
    vector<int> A;
    for(auto ch : str){
        if('0' <= ch && ch <= '9'){
            A.emplace_back((int)(ch - '0'));
        }
    }

    cout << A.at(k) << endl;
}