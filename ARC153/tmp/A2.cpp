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

class Timer{
    private:
        std::chrono::system_clock::time_point m_start;
    public:
        Timer() {
            m_start = std::chrono::system_clock::now();
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

const i64 INI = 110000000;

int main() {
    i64 N;
    cin >> N;

    cerr << fixed << setprecision(10);
    double time = 0.0;
    Timer sw = Timer();
    i64 num = INI;
    num /= 10;
    i64 cnt = 1;
    while(cnt < N){
        num += 1;
        bool OK1 = (num/100) % 10 == (num/1000) % 10;
        bool OK2 = (num/1000000) % 10 == (num/10000000) % 10;
        if(OK1 && OK2){
            cnt++;
        }
    }
    i64 add = (num/10) % 10;
    i64 ans = (num*10) + add;
    cout << ans << '\n';
    time = sw.GetTimeMS();
    debugL(time);
    debugP([ms]);

    return 0;
}