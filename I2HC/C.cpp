#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
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

const i64 POW6 = 1000000LL;
const i64 INF = (i64)2 << 60;

i64 decScore(vector<i64> &C, i64 d, vector<i64> &last){
    i64 ret = 0;
    for(int i = 1; i <= 26; i++){
        ret += C.at(i) * (d - last.at(i));
    }

    return ret;
}
vector<i64> getScore(i64 inputD, vector<i64> &inputC, vector<vector<i64>> &inputS, vector<int> &outputT){
    vector<i64> last(27, 0);
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

    return results;
}

vector<int> select(i64 inputD, vector<i64> &inputC, vector<vector<i64>> &inputS){
    vector<i64> last(27, 0);
    for(int i = 1; i <= 26; i++){
        last[i] = 0;
    }

    vector<int> outputT(inputD + 1, 0);
    for(int day = 1; day <= inputD; day++){
        i64 todayResult = -INF, resultType = 1;
        for(int todayType = 1; todayType <= 26; todayType++){
            vector<i64> tempLast(last);
            i64 tmp = inputS.at(day).at(todayType);
            tempLast.at(todayType) = day;
            tmp -= decScore(inputC, day, tempLast);
            if(todayResult < tmp){
                todayResult = tmp;
                resultType = todayType;
            }
        }
        outputT.at(day) = resultType;
        last.at(resultType) = day;
    }

    return outputT;
}

i64 calSum(i64 n){
    return ((1 + n) * n) / 2;
}

i64 calDiffScore(int d, int q, i64 inputD, vector<i64> &inputC, vector<vector<i64>> &inputS, vector<int> &t){
    i64 ret = 0;
    int prevType = t.at(d);
    ret -= inputS.at(d).at(prevType);
    ret += inputS.at(d).at(q);

    int pDay1 = 0, pDay2 = inputD + 1, qDay1 = 0, qDay2 = inputD + 1;
    for(int i = d-1; i > 0; i--){
        if(t.at(i) == prevType){
            pDay1 = i;
            break;
        }
    }
    for(int i = d+1; i <= inputD; i++){
        if(t.at(i) == prevType){
            pDay2 = i;
            break;
        }
    }
    for(int i = d-1; i > 0; i--){
        if(t.at(i) == q){
            qDay1 = i;
            break;
        }
    }
    for(int i = d+1; i <= inputD; i++){
        if(t.at(i) == q){
            qDay2 = i;
            break;
        }
    }

    i64 oldC = (calSum(d - pDay1 - 1) + calSum(pDay2 - d - 1)) * inputC.at(prevType) + calSum(qDay2 - qDay1 - 1) * inputC.at(q);
    i64 newC = calSum(pDay2 - pDay1 - 1) * inputC.at(prevType) + (calSum(d - qDay1 - 1) + calSum(qDay2 - d - 1)) * inputC.at(q);

    ret += (oldC - newC);

    t.at(d) = q;

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
    // outputT = select(inputD, inputC, inputS);
    for(int i = 1; i <= inputD; i++){
        cin >> outputT.at(i);
    }

    vector<i64> results = getScore(inputD, inputC, inputS, outputT);
    i64 nowScore = results.at(inputD);

    int M;
    cin >> M;
    while(M--){
        int d, q;
        cin >> d >> q;

        i64 diff = calDiffScore(d, q, inputD, inputC, inputS, outputT);
        nowScore += diff;

        cout << nowScore << '\n';
    }

    return 0;
}