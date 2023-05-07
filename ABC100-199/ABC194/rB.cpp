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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    int ans = INF;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                ans = min(ans, A.at(i) + B.at(j));
            }
            else{
                ans = min(ans, max(A.at(i), B.at(j)));
            }
        }
    }

    cout << ans << endl;
}