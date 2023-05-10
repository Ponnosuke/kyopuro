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

    for(int i = 0; i < 4; i++){
        reverse(TABLE.at(i).begin(), TABLE.at(i).end());
    }

    reverse(S.begin(), S.end());

    debugP();

    int N = S.size();
    bool OK = true;
    for(int i = 0; i < N;){

        debugVL(i);

        char nowCh = S.at(i);
        if(nowCh == 'm'){
            if(i+4 >= N){
                OK = false;
                break;
            }

            debugP();

            string target = TABLE.at(0);

            debugP();

            for(int j = 0; j < target.size(); j++){

                debugVL(i);
                debugV(S.at(i));
                debugVL(target.at(j));

                if(S.at(i) != target.at(j)){
                    OK = false;
                    break;
                }

                i++;
            }

            if(!OK){
                break;
            }
        }
        else if(nowCh == 'e'){
            if(i+4 >= N){
                OK = false;
                break;
            }

            string target = TABLE.at(2);

            for(int j = 0; j < target.size(); j++){
                if(S.at(i) != target.at(j)){
                    OK = false;
                    break;
                }

                i++;
            }

            if(!OK){
                break;
            }
        }
        else{

            debugP();

            if(i+5 >= N){
                OK = false;
                break;
            }

            debugP();

            string target;
            if(S.at(i+2) == 's'){
                target = TABLE.at(3);
            }
            else{
                if(i+6 >= N){
                    OK = false;
                    break;
                }

                target = TABLE.at(1);
            }

            for(int j = 0; j < target.size(); j++){

                debugVL(i);
                debugV(S.at(i));
                debugVL(target.at(j));

                if(S.at(i) != target.at(j)){
                    OK = false;
                    break;
                }

                i++;
            }

            if(!OK){
                break;
            }
        }

        debugWL();
    }

    cout << (OK ? "YES" : "NO") << endl;

    return 0;
}