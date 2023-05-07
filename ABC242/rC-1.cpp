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

class Timer{
    private:
        std::chrono::system_clock::time_point m_start;
    public:
        Timer() :m_start(std::chrono::system_clock::now()) {
            std::cerr << fixed << setprecision(18);
        }
    public:
        void Reset(){
            m_start = std::chrono::system_clock::now();
        }
        double GetTimeMS(){
            auto end = std::chrono::system_clock::now();
            return (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start).count();
        }
        double GetTimeSec(){
            auto end = std::chrono::system_clock::now();
            return (double)std::chrono::duration_cast<std::chrono::seconds>(end - m_start).count();
        }
};

const i64 MOD = 998244353;

int main() {
    i64 N;
    cin >> N;

    Timer sw = Timer();

    vector<vector<i64>> dp(N+1, vector<i64>(10, 0));
    for(int i = 1; i <= 9; i++){
        dp.at(1).at(i) = 1;
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= 9; j++){
            if(j-1 >= 1){
                dp.at(i+1).at(j-1) += dp.at(i).at(j);
                dp.at(i+1).at(j-1) %= MOD;
            }

            dp.at(i+1).at(j) += dp.at(i).at(j);
            dp.at(i+1).at(j) %= MOD;

            if(j+1 <= 9){
                dp.at(i+1).at(j+1) += dp.at(i).at(j);
                dp.at(i+1).at(j+1) %= MOD;
            }
        }
    }

    i64 ans = 0;
    for(int i = 1; i <= 9; i++){
        ans += dp.at(N).at(i);
        ans %= MOD;
    }

    cout << ans << '\n';

    debugVL(sw.GetTimeMS());
}