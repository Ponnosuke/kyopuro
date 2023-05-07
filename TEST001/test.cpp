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

const int ARRAY_SIZE = 100000000;

int main() {
    vector<int> A(ARRAY_SIZE);
    vector<int> B(ARRAY_SIZE);
    cerr << fixed << setprecision(15);

    Timer tm;
    for(int i = 0; i < ARRAY_SIZE; i++){
        A.at(i) = 3389;
    }
    debugL(tm.GetTimeMS());

    tm.Restart();
    for(auto &x : B){
        x = 3389;
    }
    debugL(tm.GetTimeMS());

    vector<int> C(ARRAY_SIZE);
    vector<int> D(ARRAY_SIZE);

    tm.Restart();
    for(int i = 0; i < ARRAY_SIZE; i++){
        C.at(i) = 3389;
    }
    debugL(tm.GetTimeMS());

    tm.Restart();
    for(auto &x : D){
        x = 3389;
    }
    debugL(tm.GetTimeMS());

}