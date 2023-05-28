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

const i64 UPPER = (1LL << 60);

i64 solver1(i64 N, vector<i64> &target){
    auto itr = upper_bound(target.begin(), target.end(), N);

    if(itr == target.begin()){
        return -1;
    }
    else{
        advance(itr, -1);
        return *itr;
    }
}

i64 solver2(i64 N){
    bitset<62> bs(N);
    if(bs.count() == 3){
        return N;
    }

    int cnt = 0;
    i64 now = 0;
    i64 add = UPPER;
    for(int rep = 0; rep <= 60; rep++){
        if(now + add < N){
            now += add;
            cnt++;
        }

        add /= 2;
        if(cnt >= 3){
            break;
        }
    }

    if(cnt == 3){
        return now;
    }
    else{
        return -1;
    }
}

// i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

return ret;
}

int main() {
    int T;
    cin >> T;

    vector<i64> target;
    for(int i = 0; i < 60; i++){
        for(int j = i+1; j < 60; j++){
            for(int k = j+1; k < 60; k++){
                target.push_back((1LL << i) + (1LL << j) + (1LL << k));
            }
        }
    }
    sort(target.begin(), target.end());

    debugWL(start);

    while(T--){
        i64 N = myRnd64(1, 1000000000000000000LL);

        i64 sol1 = solver1(N, target), sol2 = solver2(N);

        if(sol1 != sol2){
            debugWL(Wrong!);
            debugVL(N);
            debugV(sol1);
            debugVL(sol2);

            exit(1);
        }
    }

    debugWL(finish);
}