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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<bool> cut(361, false);
    int now_deg = 0;
    cut.at(now_deg) = true;
    for(int i = 0; i < N; i++){
        now_deg += A.at(i);
        now_deg %= 360;
        cut.at(now_deg) = true;
    }
    cut.at(360) = true;

    int pre_deg = 0;
    int max_deg = 0;
    for(int d = 0; d <= 360; d++){
        if(cut.at(d)){
            max_deg = max(max_deg, d - pre_deg);
            pre_deg = d;
        }
    }

    cout << max_deg << endl;
}