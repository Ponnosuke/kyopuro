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
    i64 N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<i64, i64>> itemPos;
    for(int i = 0; i < M; i++){
        i64 ix, iy;
        cin >> ix >> iy;
        itemPos.insert(make_pair(ix, iy));
    }

    bool OK = true;
    i64 x = 0, y = 0;
    for(int i = 0; i < N; i++){
        H--;
        if(H < 0){
            OK = false;
            break;
        }

        char nowCh = S.at(i);
        if(nowCh == 'R'){
            x++;
        }
        else if(nowCh == 'L'){
            x--;
        }
        else if(nowCh == 'U'){
            y++;
        }
        else{  // D
            y--;
        }

        if(itemPos.count(make_pair(x, y))){
            if(H < K){
                H = K;
                itemPos.erase(make_pair(x, y));
            }
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}