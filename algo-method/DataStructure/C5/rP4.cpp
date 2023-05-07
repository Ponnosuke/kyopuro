#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    vector<int> cnt(26, 0);
    for(int i = 0; i < N; i++){
        string w;
        cin >> w;
        for(auto ch : w){
            cnt.at(ch - 'a')++;
        }
    }

    bool OK = true;
    for(int x : cnt){
        if(x == 0){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}