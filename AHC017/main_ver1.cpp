/*
    ver1
    
    全て完全乱数
*/

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
            // std::cerr << fixed << setprecision(18);
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

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

int main() {
    int N, M, D, K;
    cin >> N >> M >> D >> K;
    vector<int> u(M, 0), v(M, 0), w(M, 0);
    for(int i = 0; i < M; i++){
        cin >> u.at(i) >> v.at(i) >> w.at(i);
    }
    vector<int> x(N, 0), y(N, 0);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i);
    }

    vector<int> r(M, 1);
    vector<int> dayCnt(D, 0);
    for(int i = 0; i < M; i++){
        int day = 1;
        do{
            day = myRnd64(1, D);
        }while(dayCnt[day-1] >= K);

        dayCnt[day-1]++;
        r.at(i) = day;
    }

    for(int i = 0; i < M; i++){
        cout << r.at(i);
        if(i < M-1){
            cout << " ";
        }
    }
    cout << '\n';
}