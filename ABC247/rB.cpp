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
    int N;
    cin >> N;
    vector<string> s(N), t(N);
    for(int i = 0; i < N; i++){
        cin >> s.at(i) >> t.at(i);
    }

    bool OK = true;
    for(int i = 0; i < N; i++){
        bool sOK = true, tOK = true;
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }

            if(s.at(i) == s.at(j) || s.at(i) == t.at(j)){
                sOK = false;
            }
            if(t.at(i) == s.at(j) || t.at(i) == t.at(j)){
                tOK = false;
            }

            if(!sOK && !tOK){
                OK = false;
            }
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}