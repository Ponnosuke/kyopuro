/*
    std::vector::insert
    std::vector::erase
    std::count
    https://kaworu.jpn.org/cpp/std::vector_%E7%89%B9%E5%AE%9A%E3%81%AE%E8%A6%81%E7%B4%A0%E3%82%92%E3%82%AB%E3%82%A6%E3%83%B3%E3%83%88%E3%81%99%E3%82%8B

    Cf: アルゴ式
    https://algo-method.com/tasks/829

*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int k, v;
            cin >> k >> v;

            A.insert(next(A.begin(), k), v);
        }
        if(type == 1){
            int k;
            cin >> k;

            A.erase(next(A.begin(), k));
        }
        if(type == 2){
            int v;
            cin >> v;

            cout << (int)count(A.begin(), A.end(), v) << '\n';
        }
    }

    return 0;
}