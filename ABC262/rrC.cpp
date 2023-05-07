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
    i64 N;
    cin >> N;
    vector<i64> a(N, 0);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        a.at(i)--;
    }

    i64 sameCnt = 0;
    i64 ans = 0;
    for(int i = 0; i < N; i++){
        if(a.at(i) == i){
            sameCnt++;
        }
        else{
            if(a.at(a.at(i)) == i && a.at(i) > i){
                ans++;
            }
        }
    }

    ans += sameCnt*(sameCnt - 1)/2;

    cout << ans << endl;
}