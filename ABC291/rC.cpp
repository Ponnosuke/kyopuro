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
    string S;
    cin >> S;

    set<pair<int, int>> sp;
    int x = 0, y = 0;
    sp.insert(make_pair(x, y));
    for(int i = 0; i < N; i++){
        char nowCh = S.at(i);
        if(nowCh == 'R'){
            x += 1;
        }
        if(nowCh == 'L'){
            x -= 1;
        }
        if(nowCh == 'U'){
            y += 1;
        }
        if(nowCh == 'D'){
            y -= 1;
        }

        if(sp.count(make_pair(x, y))){
            cout << "Yes" << '\n';
            return 0;
        }
        else{
            sp.insert(make_pair(x, y));
        }
    }

    cout << "No" << '\n';
    return 0;
}