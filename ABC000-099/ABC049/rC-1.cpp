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

vector<string> TABLE = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for(int i = 0; i < 4; i++){
        reverse(TABLE.at(i).begin(), TABLE.at(i).end());
    }

    int N = S.size();
    bool OK1 = true;
    for(int i = 0; i < N;){
        bool OK2 = false;
        for(int t = 0; t < 4; t++){
            string nowStr = TABLE.at(t);
            if(S.substr(i, (int)nowStr.size()) == nowStr){
                OK2 = true;
                i += (int)nowStr.size();
                break;
            }
        }

        if(!OK2){
            OK1 = false;
            break;
        }
    }

    cout << (OK1 ? "YES" : "NO") << endl;

    return 0;
}