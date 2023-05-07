#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugP(Z)
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> dh = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dw = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int N, X;
    cin >> N >> X;
    vector<vector<int>> field(N, vector<int>(N, 0));  // 0 := white, 1 := black
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char ch;
            cin >> ch;
            if(ch == '#'){
                field.at(i).at(j) = 1;
            }
        }
    }

    debugP(iniField);
    rep(i, N){
        rep(j, N){
            debug(field.at(i).at(j));
        }
        debugP();
    }
    debugP();

    for( ; X-- ; ){
        debugV(X);

        vector<vector<int>> cnt(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int d = 0; d < 8; d++){
                    int nh = i + dh.at(d), nw = j + dw.at(d);
                    if(0 <= nh && nh < N && 0 <= nw && nw < N){
                        cnt.at(i).at(j) += field.at(nh).at(nw);
                    }
                }
            }
        }

        debugP(cnt);
        rep(i, N){
            rep(j, N){
                debug(cnt.at(i).at(j));
            }
            debugP();
        }


        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(field.at(i).at(j) == 0){
                    if(cnt.at(i).at(j) == 3){
                        field.at(i).at(j) = 1;
                    }
                }
                else{
                    if(cnt.at(i).at(j) <= 1 || 4 <= cnt.at(i).at(j)){
                        field.at(i).at(j) = 0;
                    }
                }
            }
        }

        debugP(field);
        rep(i, N){
            rep(j, N){
                debug(field.at(i).at(j));
            }
            debugP();
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(field.at(i).at(j) == 1){
                cout << '#';
            }
            else{
                cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}