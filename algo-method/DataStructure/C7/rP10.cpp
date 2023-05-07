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
    int X;
    cin >> X;
    int Q;
    cin >> Q;

    queue<int> times;
    int cnt = 0;
    while(Q--){
        int type, t;
        cin >> type >> t;


        if(type == 0){
            times.push(t + X);
        }
        if(type == 1){
            while(!times.empty() && times.front() <= t){
                cnt++;
                times.pop();
            }
            
            cout << cnt << '\n';
        }
    }
}