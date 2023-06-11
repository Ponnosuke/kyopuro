#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
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
    v1 := 頂点1
    v2 := 頂点2
    w := v1 v2 間にある辺の長さ
    index := v1 v2 間の辺の番号
*/
struct Edge {
    i64 v1;
    i64 v2;
    i64 w;
    i64 index;

    Edge(i64 _v1, i64 _v2, i64 _w, i64 _index) : v1(_v1), v2(_v2), w(_w), index(_index) {
    }
    Edge(){
    }

    void Set(i64 _v1, i64 _v2, i64 _w, i64 _index){
        v1 = _v1;
        v2 = _v2;
        w = _w;
        index = _index;

        return;
    }
};

struct Point{
    i64 x;
    i64 y;

    Point(i64 ix, i64 iy) :x(ix), y(iy) {
    }

    Point(){
    }

    void Set(i64 ix, i64 iy){
        x = ix;
        y = iy;

        return;
    }

    Point operator +(const Point &other){
        return Point(x + other.x, y + other.y);
    }
    Point operator -(const Point &other){
        return Point(x - other.x, y - other.y);
    }
    Point operator *(const i64 &multNum){
        return Point(x * multNum, y * multNum);
    }
    Point operator /(const i64 &divNum){
        return Point(x / divNum, y / divNum);
    }
};

i64 get_point_dist2(Point p1, Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

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

void output_func(vector<i64> &output_P, vector<i64> &output_B, i64 &input_N, i64 &input_M){
    for(int i = 0; i < input_N; i++){
        cout << output_P.at(i);

        if(i < input_N - 1){
            cout << " ";
        }
    }
    cout << '\n';

    for(int i = 0; i < input_M; i++){
        cout << output_B.at(i);

        if(i < input_M - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return;
}

int main() {
    i64 input_N, input_M, input_K;
    cin >> input_N >> input_M >> input_K;
    // 放送局
    vector<i64> input_x(input_N, 0), input_y(input_N, 0);
    for(int i = 0; i < input_N; i++){
        cin >> input_x.at(i) >> input_y.at(i);
    }
    // 放送局間
    vector<i64> input_u(input_M, 0), input_v(input_M, 0), input_w(input_M, 0);
    for(int i = 0; i < input_M; i++){
        cin >> input_u.at(i) >> input_v.at(i) >> input_w.at(i);
        input_u.at(i)--;
        input_v.at(i)--;
    }
    // 住民の座標
    vector<i64> input_a(input_K, 0), input_b(input_K, 0);
    for(int i = 0; i < input_K; i++){
        cin >> input_a.at(i) >> input_b.at(i);
    }


    vector<i64> output_P(input_N, 5000), output_B(input_M, 1);

    

    output_func(output_P, output_B, input_N, input_M);

    return 0;
}