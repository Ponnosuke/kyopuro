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

int main() {
    double time = 0.0;
    Timer sw = Timer();
    i64 N;
    cin >> N;

    sw.Reset();
    i64 cnt = 0;
    for(i64 num = 1; num <= N; num++){
        i64 tmp1 = num;
        for(i64 i = 2; i * i <= tmp1; i++){
            i64 square = i*i;
            while(tmp1 % square == 0){
                tmp1 /= square;
            }
        }

        for(int i = 1; tmp1 * i * i <= N; i++){
            cnt++;
        }
    }

    cout << cnt << '\n';
    time = sw.GetTimeMS();
    debug(time);
    debugP([ms]);
}