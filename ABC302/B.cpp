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

vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }

    bool OK = false;
    vector<pair<int, int>> ans;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int ini_x = j, ini_y = i;

            for(int d = 0; d < 8; d++){
                string str = "";
                int now_x = ini_x, now_y = ini_y;
                while(0 <= now_x && now_x < W && 0 <= now_y && now_y < H && (int)str.size() < 5){
                    str += S.at(now_y).at(now_x);
                    now_y += dy.at(d), now_x += dx.at(d);
                }

                if(str == "snuke"){
                    OK = true;
                    for(int rep = 0; rep < 5; rep++){
                        now_y -= dy.at(d);
                        now_x -= dx.at(d);
                        ans.emplace_back(now_y, now_x);
                    }
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

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i).first + 1 << " " << ans.at(i).second + 1 << '\n';
    }

    return 0;
}