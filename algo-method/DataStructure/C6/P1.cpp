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

const int BASE = 27;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    debugP();

    i64 size = BASE*BASE*BASE*BASE;
    vector<int> cnt(size + 1, 0);
    for(int i = 0; i < N; i++){
        i64 add = 0, num = 0;

        debugP();
        for(int j = 0; j < S.at(i).size(); j++){
            num *= BASE;
            add = S.at(i).at(j) - 'a' + 1;
            num += add;
        }
        debugP();

        cnt.at(num)++;
    }

    debugP();

    int Q;
    cin >> Q;
    while(Q--){
        string T;
        cin >> T;

        debugP();

        i64 add = 0, num = 0;
        for(int i = 0; i < T.size(); i++){
            num *= BASE;
            add = T.at(i) -'a' + 1;
            num += add;
        }

        debugP();

        cout << cnt.at(num) << '\n';
    }

    return 0;
}