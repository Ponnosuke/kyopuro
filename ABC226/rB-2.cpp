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
    vector<vector<i64>> a(N);
    for(int i = 0; i < N; i++){
        i64 L;
        cin >> L;

        for(int j = 0; j < L; j++){
            i64 iA;
            cin >> iA;
            a.at(i).push_back(iA);
        }
    }

    sort(a.begin(), a.end());

    i64 cnt = 1;
    for(int i = 1; i < N; i++){
        if(a.at(i-1) != a.at(i)){
            cnt++;
        }
    }

    cout << cnt << endl;
}