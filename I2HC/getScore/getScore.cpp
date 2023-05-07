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

const i64 POW6 = 1000000LL;

i64 decScore(vector<i64> &C, i64 d, map<int, i64> &last){
    i64 ret = 0;
    for(int i = 1; i <= 26; i++){
        ret += C.at(i) * (d - last.at(i));
    }

    return ret;
}

int main() {
    i64 inputD;
    cin >> inputD;
    vector<i64> inputC(27, 0);
    for(int i = 1; i < 27; i++)  cin >> inputC.at(i);
    vector<vector<i64>> inputS(inputD + 1, vector<i64>(27, 0));
    for(int i = 1; i < inputD + 1; i++){
        for(int j = 1; j < 27; j++){
            cin >> inputS.at(i).at(j);
        }
    }
    vector<int> outputT(inputD + 1, 0);
    for(int i = 1; i < inputD + 1; i++)  cin >> outputT.at(i);

    map<int, i64> last;
    for(int i = 1; i <= 26; i++){
        last[i] = 0;
    }

    vector<i64> results(inputD+1, 0);
    i64 result = 0;
    for(int day = 1; day <= inputD; day++){
        i64 todayContest = outputT.at(day);
        result += inputS.at(day).at(todayContest);
        last.at(todayContest) = day;
        result -= decScore(inputC, day, last);
        results.at(day) = result;
    }

    for(int i = 1; i <= inputD; i++){
        cout << results.at(i) << '\n';
    }
}