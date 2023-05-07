/*
    D - Three Days Ago https://atcoder.jp/contests/abc295/tasks/abc295_d 

    愚直解
    O(N^2) なので恐らく TLE になる
*/

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
            Snum.at(j).at(i+1) += Snum.at(j).at(i);
        }
    }

    i64 ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            bool flag = true;
            bool oddCnt = false, evenCnt = false;
            for(int k = 0; k <= 9; k++){
                i64 diff = Snum.at(k).at(j) - Snum.at(k).at(i);
                debugV(i);
                debugV(j);
                debugVL(k);
                debugV(Snum.at(k).at(j));
                debugVL(Snum.at(k).at(i));
                debugVL(diff);
                if(diff > 0 && diff % 2 == 0){
                    evenCnt = true;
                }
                else if(diff % 2 == 1){
                    oddCnt = true;
                }
            }

            if(evenCnt && !oddCnt){
                flag = true;
            }
            else{
                flag = false;
            }

            if(flag){
                ans++;
            }
        }
    }

    cout << ans << '\n';
}