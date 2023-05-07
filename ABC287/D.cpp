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
    string S, T;
    cin >> S >> T;

    int Tsize = T.size(), Ssize = S.size();

    // vector<bool> isMatch(Tsize + 1, false);
    int matchCnt = 0;
    int missMatch = 0;
    bool OK = true;
    for(int x = 0; x <= Tsize; x++){
        if(x == 0){
            string Sdash = S.substr(Ssize - (Tsize - x), Tsize - x);

            for(int i = 0; i < Tsize; i++){
                char nowSdash = Sdash.at(i), nowT = T.at(i);
                if(nowSdash == '?' || nowT == '?' || nowSdash == nowT){
                    matchCnt++;
                }
                else{
                    missMatch++;
                }
            }

            if(matchCnt == Tsize){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }
        }
        else{
            char nowS = S.at(x-1), nowT = T.at(x-1), prevS = S.at(Ssize - (Tsize - (x-1)));

            debugVL(x);
            debugV(nowS);
            debugVL(nowT);
            debugWL(before);
            debugVL(matchCnt);

            if(prevS == '?' || prevS == nowT || nowT == '?'){
                matchCnt--;
            }

            if(nowS == nowT || nowS == '?' || nowT == '?'){
                matchCnt++;
            }


            debugWL(after);
            debugVL(matchCnt);

            if(matchCnt == Tsize && OK){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }

            debugWL();
        }
    }
}