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
    int H, W;
    cin >> H >> W;
    vector<string> Sc(W, ""), Tc(W, "");
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char ch;
            cin >> ch;
            Sc.at(j) += ch;
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char ch;
            cin >> ch;
            Tc.at(j) += ch;
        }
    }
    map<string, int> Smp, Tmp;
    for(int i = 0; i < W; i++){
        Smp[Sc.at(i)]++;
        Tmp[Tc.at(i)]++;
    }

    bool OK = true;
    for(auto [str, cnt] : Smp){
        if(Smp[str] != Tmp[str]){
            OK = false;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}