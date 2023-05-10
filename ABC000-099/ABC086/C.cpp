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
    int N;
    cin >> N;
    vector<int> t(N), x(N), y(N);
    for(int i = 0; i < N; i++){
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }

    int now_t = 0, now_x = 0, now_y = 0;
    bool OK = true;
    for(int i = 0; i < N; i++){
        int diff_t = t.at(i) - now_t;
        int dist = abs(x.at(i) - now_x) + abs(y.at(i) - now_y);

        if(diff_t < dist){
            OK = false;
            break;
        }
        if(t.at(i) % 2 != (abs(x.at(i)) + abs(y.at(i))) % 2){
            OK = false;
            break;
        }

        now_t = t.at(i);
        now_x = x.at(i);
        now_y = y.at(i);
    }

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}