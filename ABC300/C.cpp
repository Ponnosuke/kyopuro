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

vector<int> dx = {-1, 1, 1, -1};
vector<int> dy = {1, 1, -1, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H+2, vector<char>(W+2, '.'));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> C.at(i).at(j);
        }
    }

    debugP();

    vector<int> ans(min(H, W) + 1, 0);
    vector<vector<bool>> used(H+2, vector<bool>(W+2, false));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            debugV(i);
            debugVL(j);

            int sizeCnt = 0;
            int nowX = j, nowY = i;

            int tmpCnt = 0;
            while(C.at(nowY).at(nowX) == '#' && !used.at(nowY).at(nowX)){
                debugP();
                used.at(nowY).at(nowX) = true;
                tmpCnt++;
                nowX += 1;
                nowY += 1;
            }

            nowX--;
            nowY--;
            sizeCnt = tmpCnt/2;
            int centerX = j + sizeCnt, centerY = i + sizeCnt;
            int n = 0;
            while(n < sizeCnt){
                n++;
                for(int d = 0; d < 4; d++){
                    debugV(centerY + n*dy.at(d));
                    debugVL(centerX + n*dx.at(d));
                    used.at(centerY + n*dy.at(d)).at(centerX + n*dx.at(d)) = true;
                }
            }

            if(sizeCnt > 0){
                ans.at(sizeCnt)++;
            }
        }
    }

    debugP();

    for(int i = 1; i <= min(H, W); i++){
        cout << ans.at(i);

        if(i < min(H, W)){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}