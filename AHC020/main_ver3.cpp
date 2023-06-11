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

const i64 I64_INF = (1LL << 60);

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
    vector<vector<Edge>> G(input_N);
    for(int i = 0; i < input_M; i++){
        cin >> input_u.at(i) >> input_v.at(i) >> input_w.at(i);
        input_u.at(i)--;
        input_v.at(i)--;
        G.at(input_u.at(i)).push_back(Edge(input_u.at(i), input_v.at(i), input_w.at(i), i));
        G.at(input_v.at(i)).push_back(Edge(input_v.at(i), input_u.at(i), input_w.at(i), i));
    }
    // 住民の座標
    vector<i64> input_a(input_K, 0), input_b(input_K, 0);
    for(int i = 0; i < input_K; i++){
        cin >> input_a.at(i) >> input_b.at(i);
    }

    vector<Point> housou_point(input_N);
    for(int i = 0; i < input_N; i++){
        housou_point.at(i) = Point(input_x.at(i), input_y.at(i));
    }
    vector<Point> jumin_point(input_K);
    for(int i = 0; i < input_K; i++){
        jumin_point.at(i) = Point(input_a.at(i), input_b.at(i));
    }

    debugP();

    i64 max_zyuumin_to_housou_dist2 = -1;
    vector<bool> need_housou(input_N, false);
    need_housou.at(0) = true;
    for(int i = 0; i < input_K; i++){
        i64 nearest_housou_dist2 = I64_INF;
        i64 cor_housou_idx = 0;
        for(int j = 0; j < input_N; j++){
            i64 cor_dist2 = get_point_dist2(jumin_point.at(i), housou_point.at(j));
            if(nearest_housou_dist2 == cor_dist2){
                if(need_housou.at(cor_housou_idx)){
                    continue;
                }
                else{
                    cor_housou_idx = j;
                }
            }
            else if(nearest_housou_dist2 > cor_dist2){
                nearest_housou_dist2 = cor_dist2;
                cor_housou_idx = j;
            }
        }

        need_housou.at(cor_housou_idx) = true;
        max_zyuumin_to_housou_dist2 = max(max_zyuumin_to_housou_dist2, nearest_housou_dist2);
    }

    // 必要な放送局を探索
    bool OK = false;
    i64 need_housou_cnt = 0;
    for(int i = 0; i < input_N; i++){
        if(need_housou.at(i)){
            need_housou_cnt++;
        }
    }
    // MEMO: dfs の方が良さそう
    queue<i64> que;
    vector<bool> visited(input_N, false);
    visited.at(0) = true;
    que.push(0);
    i64 now_housou_cnt = 0;
    vector<i64> output_B(input_M, 0);
    while(!que.empty()){
        i64 now = que.front();
        que.pop();
        for(Edge nxt : G.at(now)){
            i64 nv = nxt.v2;
            if(visited.at(nv)){
                continue;
            }

            que.push(nv);
            visited.at(nv) = true;
            output_B.at(nxt.index) = 1;

            if(need_housou.at(nv)){
                now_housou_cnt++;
            }

            if(now_housou_cnt == need_housou_cnt){
                OK = true;
                break;
            }
        }

        if(OK){
            break;
        }
    }

    i64 max_P = (i64)(sqrt(max_zyuumin_to_housou_dist2) + 0.5);
    vector<i64> output_P(input_N, 0);
    for(int i = 0; i < input_N; i++){
        if(need_housou.at(i)){
            output_P.at(i) = max_P;
        }
    }

    output_func(output_P, output_B, input_N, input_M);

    return 0;
}