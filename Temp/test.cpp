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

// 非再帰のユークリッド互除法による逆元計算
// a の mod m における逆元を求める  
// a と m が互いに素でないといけないことに注意
i64 modinv(i64 a, i64 m){
    i64 b = m, s = 1, t = 0;
    while(b){
        i64 q = a / b;
        a -= q * b;
        swap(a, b);
        s -= q * t;
        swap(s, t);
    }
    s = ((s % m) + m) % m;
    return s;
}

// 再帰ユークリッド互除法による逆元計算のセット
i64 extGCD(i64 a, i64 b, i64 &x, i64 &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    i64 g = extGCD(b, a%b, y, x);
    y -= (a/b) * x;
    return g;
}
i64 tempModInv(i64 a, i64 m){
    i64 x, y;
    extGCD(a, m, x, y);
    return ((x % m) + m) % m;
}


const i64 MOD = 1000000007;
const i64 LOOP = 1000000;
const i64 COUNT = 100;
const int ZERO = 0;

int main() {
    cout << "start" << '\n';

    Timer tm;
    cerr << fixed << setprecision(7);
    double modinvTime = 0.0, tempModInvTime = 0.0;
    double sum1 = ZERO, sum2 = ZERO;

    for(int i = 0; i < COUNT; i++){
        tm.Restart();
        for(int i = 1; i < LOOP; i++){
            modinv(i, MOD);
        }
        modinvTime = tm.GetTimeMS();
        sum1 += modinvTime;
        debugL(modinvTime);
    }
    for(int i = 0; i < COUNT; i++){
        tm.Restart();
        for(int i = 1; i < LOOP; i++){
            tempModInv(i, MOD);
        }
        tempModInvTime = tm.GetTimeMS();
        sum2 += tempModInvTime;
        debugL(tempModInvTime);
    }

    double modinvResult = sum1/COUNT, tempModInvResult = sum2/COUNT;
    debugP();
    debugL(modinvResult);
    debugP();
    debugL(tempModInvResult);

    cout << "end" << '\n';
}