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
    vector<int> T(N, 0);
    int sum = 0;
    for(int i = 0; i < N; i++){
        int iT;
        cin >> iT;

        T.at(i) = iT;
        sum += iT;
    }

    bitset<100001> dp("1");
    for(int i = 0; i < N; i++){
        dp |= (dp << T.at(i));
    }

    int ans = sum;
    for(int i = 0; i <= 100000; i++){
       if(dp.test(i)){
            ans = min(ans, max(i, sum - i));
       }
    }

    cout << ans << '\n';
}