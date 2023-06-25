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

bool is_kaibun(string S, string T){
    int N = (int)S.size() + (int)T.size();
    int l = 0, r = N-1;
    string str = "";
    str += S;
    str += T;
    bool ret = true;
    for(int i = 0; i <= ((N-1)/2); i++){
        if(str.at(l+i) != str.at(r-i)){
            ret = false;
            break;
        }
    }

    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    bool OK = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }
            
            if(is_kaibun(S.at(i), S.at(j))){
                OK = true;
                break;
            }
        }

        if(OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}