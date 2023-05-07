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
    string S;
    cin >> S;
    int N = S.size();
    vector<i64> numCnt(10, 0);
    vector<vector<i64>> Snum(10, vector<i64>(N+1, 0));
    for(int i = 0; i < N; i++){
        char ch = S.at(i);
        int num = (int)(ch - '0');

        Snum.at(num).at(i+1)++;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 9; j++){
            Snum.at(j).at(i) %= 2;
            Snum.at(j).at(i+1) += Snum.at(j).at(i);
            Snum.at(j).at(i+1) %= 2;
        }
    }

    debugP();

    vector<i64> cnt((1 << 10), 0);
    for(int i = 0; i <= N; i++){
        i64 now = 0;
        i64 times = 1;
        for(int j = 0; j <= 9; j++){
            Snum.at(j).at(i) %= 2;
            now += Snum.at(j).at(i)*times;
            times *= 2;
        }
        cnt.at(now)++;
    }

    i64 ans = 0;
    for(i64 ele : cnt){
        ans += ele*(ele - 1) / 2;
    }

    cout << ans << '\n';
}