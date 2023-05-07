/*
* gcd() と lcm() は C++ 17 から実装されている
* gcc でコンパイルする場合は、自分の現在の環境 (gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0)
* だと  `g++ hoge.cpp -std=c++17` のコマンドでコンパイル (c++17 の機能を有効にする)
* GCC 11.1 以降は C++17 がデフォルトになっている。
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// ユークリッドの互除法を用いた GCD を求める関数
i64 myGCD(i64 a, i64 b){
    if(b == 0){
        return a;
    }
    else{
        return myGCD(b, a % b);
    }
}
/*
1. 大きい方を小さい方で割る
2. 大きい方を 1で出た余りに置き換える

a < b のときも a % b = a なので再帰呼び出しのところで入れ替わる
また、 a >= b を満たしたら b > a%b となることより、
再帰的に呼び出される関数たちは常に a > b を満たす
*/

i64 myGCD2(i64 a, i64 b){
    return (b ? myGCD2(b, a % b) : a);
}
/*
簡易化
b == 0 だと false, それ以外だと(であってるかな, ようは値があると) trueを返すことを利用
*/

/*
    非再帰の実装
*/
i64 myGCD3(i64 a, i64 b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

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

const int MAX_NUM = 1000;

int main() {
    cout << fixed << setprecision(15);
    double time1 = 0, time2 = 0, time3 = 0;
    Timer sw = Timer();
    for(int i = 1; i <= MAX_NUM; i++){
        for(int j = 1; j <= MAX_NUM; j++){
            gcd(i, j);
        }
    }
    time1 = sw.GetTimeMS();

    sw.Reset();
    for(int i = 1; i <= MAX_NUM; i++){
        for(int j = 1; j <= MAX_NUM; j++){
            myGCD(i, j);
        }
    }
    time2 = sw.GetTimeMS();

    sw.Reset();
    for(int i = 1; i <= MAX_NUM; i++){
        for(int j = 1; j <= MAX_NUM; j++){
            myGCD3(i, j);
        }
    }
    time3 = sw.GetTimeMS();

    cout << "gcd(): " << time1 << "[ms]" << '\n';
    cout << "myGCD(): " << time2 << "[ms]" << '\n';
    cout << "myGCD3(): " << time3 << "[ms]" << '\n';

    return 0;
}

/*
    OUTPUT (Local): MAX_NUM = 1000

    gcd(): 64.000000000000000[ms]
    myGCD(): 82.000000000000000[ms]
    myGCD3(): 84.000000000000000[ms]
*/

/*
    OUTPUT (AtCoder): MAX_NUM = 1000

    gcd(): 50.000000000000000[ms]
    myGCD(): 72.000000000000000[ms]
    myGCD3(): 71.000000000000000[ms]
*/