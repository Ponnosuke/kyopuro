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
        void Restart(){
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

map<int, i64> memo;

i64 F(int N){
    if(memo.count(N)){
        return memo.at(N);
    }
    if(N == 0 || N == 1){
        return 1;
    }

    i64 ret = 0;
    ret = F(N-1) + F(N-2);
    memo[N] = ret;

    return ret;
}

int main() {
    cerr << fixed << setprecision(10);
    Timer sw = Timer();
    i64 test = 0;

    int N;
    cin >> N;

    double inputTime = sw.GetTimeMS();
    debug(inputTime);
    debugP([ms]);
    sw.Restart();
    
    cout << F(N) << '\n';

    double time = sw.GetTimeMS();
    debug(time);
    debugP([ms]);

    return 0;
}