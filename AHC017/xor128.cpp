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


/*
    "xor128()" is from shindannin's code.
    https://atcoder.jp/contests/intro-heuristics/submissions/15905939 
*/
uint32_t xor128() 
{
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;
 
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

uint32_t xRnd(uint32_t L, uint32_t R){
    uint32_t ret = L + (xor128() % (R - L + 1));
    return ret;
}

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const int LOOP = 10000000;

int main() {
    Timer sw = Timer();
    double time = 0.0;
    
    int cnt = LOOP;
    vector<int> vCnt(7, 0);
    sw.Reset();
    for(;cnt--;){
        vCnt.at(xRnd(1, 6))++;
    }
    time = sw.GetTimeMS();

    cerr << "xor128" << '\n';
    for(int i = 1; i <= 6; i++){
        cerr << i << " :  " << vCnt.at(i) << '\n';
    }
    cerr << "time = " << time << '\n';

    cnt = LOOP;
    vCnt = vector<int>(7, 0);
    sw.Reset();
    for(;cnt--;){
        vCnt.at(myRnd64(1, 6))++;
    }
    time = sw.GetTimeMS();

    cerr << "myRnd64" << '\n';
    for(int i = 1; i <= 6; i++){
        cerr << i << " :  " << vCnt.at(i) << '\n';
    }
    cerr << "time = " << time << '\n';

}

/*
    const int LOOP = 100000000;
    OUTPUT:

    xor128
    1 :  16671635
    2 :  16670662
    3 :  16663205
    4 :  16665899
    5 :  16662691
    6 :  16665908
    time = 1620.000000000000000000
    myRnd64
    1 :  16666654
    2 :  16666664
    3 :  16668581
    4 :  16660022
    5 :  16666618
    6 :  16671461
    time = 868802.000000000000000000
*/