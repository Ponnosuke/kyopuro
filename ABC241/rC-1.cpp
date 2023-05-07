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

vector<int> dx = {1, 1, 0, -1};
vector<int> dy = {0, 1, 1, 1};

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
            for(int d = 0; d < 4; d++){
                int cntA = 0, cntW = 0;
                int x = j, y = i;

                while(cntA < 6){
                    cntA++;
                    if(S.at(y).at(x) == '.'){
                        cntW++;
                    }

                    x += dx.at(d), y += dy.at(d);
                    if(x < 0 || N <= x || y < 0 || N <= y){
                        break;
                    }
                }

                if((cntA == 6) && (cntW <= 2)){
                    OK = true;
                    break;
                }
            }

            if(OK){
                break;
            }
        }

        if(OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}