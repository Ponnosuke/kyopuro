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

// i64乱数ジェネレーター
// myRnd32() よりこっちの方が高速な可能性が高い(ローカルでもAtCoderオンラインコンパイルでも)。
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

// 愚直解
i64 solver1(i64 N, i64 K, vector<i64> &A){
    vector<i64> rui(N+1, 0);
    for(int i = 0; i < N; i++){
        rui.at(i+1) = A.at(i) + rui.at(i);
    }

    i64 ans = 0;
    for(int l = 0; l <= N; l++){
        for(int r = l; r <= N; r++){
            if((rui.at(r) - rui.at(l)) == K){
                ans++;
            }
        }
    }

    return ans;
}

i64 solver2(i64 N, i64 K, vector<i64> &A){
    vector<i64> rui(N+1, 0);
    for(int i = 0; i < N; i++){
        rui.at(i+1) = rui.at(i) + A.at(i);
    }

    map<i64, i64> mp;  // num, cnt
    for(int i = 0; i <= N; i++){
        mp[rui.at(i)]++;
    }

    i64 ans = 0;
    for(auto [num, cnt1] : mp){
        // debugVL(num);

        // debugWL();
        if(mp.count(num + K)){

            // debugV(num);
            // debugVL(num + K);
            // debugV(mp[num]);
            // debugVL(mp[num + K]);

            i64 cnt2 = mp.at(num + K);
            ans += (cnt1 * cnt2);

            // debugV(cnt1);
            // debugV(cnt2);
            // debugVL(ans);
            // debugWL();
        }
    }

    return ans;
}

const i64 LOOP_CNT = 100;

const i64 POW15 = 1000000000000000LL;
const i64 POW9 = 1000000000LL;

int main() {
    debugWL(start);
    for(int rep = 0; rep < LOOP_CNT; rep++){
        debugVL(rep);
        i64 N = myRnd64(1, 1000);
        i64 K = myRnd64(-POW15, POW15);
        // i64 K = 10;

        debugVL(K);

        vector<i64> A(N);
        for(int i = 0; i < N; i++){
            A.at(i) = myRnd64(-POW9, POW9);
            // A.at(i) = 16;
        }

        i64 sol1 = solver1(N, K, A);
        i64 sol2 = solver2(N, K, A);
        if(sol1 != sol2){
            debugWL(Wrong!);

            debugV(N);
            debugVL(K);
            debugWL(A:);
            for(int i = 0; i < N; i++){
                debug(A.at(i));
            }
            debugWL();
            debugV(sol1);
            debugVL(sol2);

            exit(1);
        }
    }
    debugWL(finish);
}