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

const string TABLE = "atcoder";

int main() {
    string S, T;
    cin >> S >> T;

    i64 N = S.size();

    map<char, i64> cntS, cntT;
    for(i64 i = 0; i < N; i++){
        cntS[S.at(i)]++;
        cntT[T.at(i)]++;
    }

    // debug
    // sort(S.begin(), S.end());
    // sort(T.begin(), T.end());


    i64 attoS = cntS['@'], attoT = cntT['@'];
    bool OK = true;
    for(char ch = 'a'; ch <= 'z'; ch++){
        i64 cS = cntS[ch], cT = cntT[ch];
        if(cS != cT){
            bool canChange = false;
            for(char c : TABLE){
                if(ch == c){
                    canChange = true;
                    break;
                }
            }

            if(!canChange){
                OK = false;
                break;
            }
            else{
                i64 diff = abs(cS - cT);
                if(cS > cT){
                    attoT -= diff;
                }
                else{
                    attoS -= diff;
                }

                if(attoT < 0 || attoS < 0){
                    OK = false;
                    break;
                }
            }
        }
    }

    // debug
    debugVL(S);
    debugVL(T);
    debugV(attoS);
    debugVL(attoT);

    cout << (OK ? "Yes" : "No") << '\n';
}