#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

const i64 SIZE = 100001;

int main() {
    int N;
    cin >> N;
    i64 sum = 0;
    vector<i64> cnt(SIZE, 0);
    for(int i = 0; i < N; i++){
        i64 A;
        cin >> A;
        cnt.at(A)++;
        sum += A;
    }

    int Q;
    cin >> Q;
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            i64 v;
            cin >> v;
            sum += v;
            cnt.at(v)++;
        }
        if(type == 1){
            i64 x, y;
            cin >> x >> y;
            i64 diff = y - x;
            cnt.at(y) += cnt.at(x);
            sum += diff * cnt.at(x);
            cnt.at(x) = 0;
        }
        if(type == 2){
            cout << sum << '\n';
        }
    }
}