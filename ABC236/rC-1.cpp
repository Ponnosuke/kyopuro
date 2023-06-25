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
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(auto &ele : S){
        cin >> ele;
    }
    vector<string> T(M);
    for(auto &ele : T){
        cin >> ele;
    }

    set<string> rapid(T.begin(), T.end());
    for(auto ele : S){
        if(rapid.count(ele)){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}