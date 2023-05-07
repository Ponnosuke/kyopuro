/*
    乱数生成用の関数一覧
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// i64乱数ジェネレーター
// myRnd32() よりこっちの方が高速な可能性が高い(ローカルでもAtCoderオンラインコンパイルでも)。
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

// int乱数ジェネレーター
// こっちの方が遅い説ある
// [L, R] を満たす int 型のランダムな整数を返す
// ただし、mt19937 は uint32_t 型を返していることに注意
int myRnd32(int L, int R){
    random_device seedGen;
    mt19937 rd(seedGen());

    int ret = L + (rd() % (R - L + 1));

    return ret;
}

// 旧myRnd()
i64 oldMyRnd64(i64 L, i64 R);
int oldMyRnd32(int L, int R);

const i64 LOOP = 100000;
enum{
    RANDOM32,
    RANDOM64,
};
const i64 FLAG = RANDOM32;
const i64 LEFT = 1;
const i64 RIGHT = 6;

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
    // cout << "myRnd32 = " << myRnd32(0, (1 << 30)) << "\n";
    // cout << "myRnd64 = " << myRnd64(0LL, (1LL << 62)) << "\n";

    map<int, i64> mp;
    i64 th = LOOP / 10, progress = 0;
    Timer tm;
    double timeResult32 = 0.0, timeResult64 = 0.0;
    cout << fixed << setprecision(10);

    tm.Restart();
    for(int i = 0; i < LOOP; i++){
        // mp[myRnd32(LEFT, RIGHT)]++;
        myRnd32(LEFT, RIGHT);
        
        if((i+1) % th == 0){
            progress += 10;
            cout << "progress: " << progress << "%\n";
        }
    }
    timeResult32 = tm.GetTimeMS();
    /*
    cout << "myRnd32() ";
    cout << "result:\n";
    cout << "Time: " << timeResult32 << '\n';
    for(auto [key, value] : mp){
        cout << "key, cnt = " << key << ", " << value << '\n';
    }
    */

    tm.Restart();
    for(int i = 0; i < LOOP; i++){
        // mp[myRnd64(LEFT, RIGHT)]++;
        myRnd64(LEFT, RIGHT);
        
        if((i+1) % th == 0){
            progress += 10;
            cout << "progress: " << progress << "%\n";
        }
    }
    timeResult64 = tm.GetTimeMS();
    /*
    cout << "myRnd64() ";   
    cout << "result:\n";
    cout << "Time: " << timeResult64 << '\n';
    for(auto [key, value] : mp){
        cout << "key, cnt = " << key << ", " << value << '\n';
    }
    */

    cout << '\n';
    cout << "times: \n";
    cout << "myRnd64: " << timeResult64 << '\n';
    cout << "myRnd32: " << timeResult32 << '\n';

    /*
    if(FLAG == RANDOM32){
        for(int i = 0; i < LOOP; i++){
            mp[myRnd32(1,6)]++;
            
            if((i+1) % th == 0){
                progress += 10;
                cout << "progress: " << progress << "%\n";
            }
        }

        cout << "myRnd32() ";
    }
    if(FLAG == RANDOM64){
        for(int i = 0; i < LOOP; i++){
            mp[myRnd64(1,6)]++;
            
            if((i+1) % th == 0){
                progress += 10;
                cout << "progress: " << progress << "%\n";
            }
        }

        cout << "myRnd64() ";        
    }

    cout << "result:\n";

    for(auto [key, value] : mp){
        cout << "key, cnt = " << key << ", " << value << '\n';
    }
    */
}


// 旧i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 oldMyRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}


// 旧int乱数ジェネレーター
// [L, R] を満たす int 型のランダムな整数を返す
// ただし、mt19937 は uint32_t 型を返していることに注意
int oldMyRnd32(int L, int R){
    random_device seedGen;
    mt19937 rd(seedGen());

    int ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}