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


// 処理時間計測用のクラス
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


int main() {
    Timer tm;
    cerr << fixed << setprecision(18);


    vector<int> A(100000000);
    for(int i = 0; i < 100000000; i++){
        A.at(i) = 3389;
    }

    double point1 = tm.GetTimeMS();
    debugL(point1);

    tm.Restart();

    vector<int> B(100000000);
    for(int i = 0; i < 100000000; i++){
        B.at(i) = 3389;
    }

    double point2 = tm.GetTimeMS();
    debugL(point2);
}