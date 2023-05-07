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
    int A, B;
    cin >> A >> B;

    if(A > B){
        swap(A, B);
    }

    int ans = INF;

    // i := 不自然な アジフライの数
    for(int i = 0; i <= A; i++){
        int fusizen = 0, sizen = 0;

        // アジ
        fusizen += i;
        sizen += A - i;

        // エビ
        fusizen += A - (A - i);
        sizen += B - i;

        ans = min(ans, abs(fusizen - sizen));
    }

    cout << ans << endl;
    
    return 0;
}