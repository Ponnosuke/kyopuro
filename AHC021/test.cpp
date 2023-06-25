/*
    ver2
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

int get_ball_pos_index(Point p){
    int x = p.x, y = p.y;
    return x*(x+1)/2 + y;
}

const int LOOP_MAX = 10000;

bool is_correct_order(vector<vector<int>> &b, Point now_ball, Point next_ball){
    int x1 = now_ball.x, y1 = now_ball.y;
    int x2 = next_ball.x, y2 = next_ball.y;

    return b.at(x1).at(y1) < b.at(x2).at(y2);
}

void operation_rec(vector<Point> &op1, vector<Point> &op2, Point ball1, Point ball2){
    int x1 = ball1.x, y1 = ball1.y;
    int x2 = ball2.x, y2 = ball2.y;

    op1.emplace_back(Point(x1, y1));
    op2.emplace_back(Point(x2, y2));

    return;
}

void swap_balls(vector<vector<int>> &b, Point ball1, Point ball2, vector<Point> &op1, vector<Point> &op2){
    int x1 = ball1.x, y1 = ball1.y;
    int x2 = ball2.x, y2 = ball2.y;

    swap(b.at(x1).at(y1), b.at(x2).at(y2));
    operation_rec(op1, op2, ball1, ball2);

    return;
}


void naive_solution(int N, vector<vector<int>> &b, vector<Point> &op1, vector<Point> &op2, int &K){
    // K = 0;
    while(K < LOOP_MAX){
        bool out = true;
        for(int i = 0; i < N-1; i++){
            for(int j = 0; j <= i; j++){
                Point now_ball = Point(i, j);
                Point next_ball1 = Point(i+1, j), next_ball2 = Point(i+1, j+1);

                if(!is_correct_order(b, now_ball, next_ball1) && !is_correct_order(b, now_ball, next_ball2)){
                    int selector_num = xRnd(1, 2);

                    if(selector_num == 1){
                        swap_balls(b, now_ball, next_ball1, op1, op2);
                        K++;
                        out = false;
                        continue;
                    }
                    else{
                        swap_balls(b, now_ball, next_ball2, op1, op2);
                        K++;
                        out = false;
                        continue;
                    }
                }

                if(!is_correct_order(b, now_ball, next_ball1)){
                    swap_balls(b, now_ball, next_ball1, op1, op2);
                    K++;
                    out = false;
                    continue;
                }

                if(!is_correct_order(b, now_ball, next_ball2)){
                    swap_balls(b, now_ball, next_ball2, op1, op2);
                    K++;
                    out = false;
                    continue;
                }
            }
        }

        if(out){
            break;
        }
    }

    return;
}

void sort_each_row(int N, vector<vector<int>> &b, int &K, vector<Point> &op1, vector<Point> &op2){
    for(int i = 0; i < N; i++){

        for(int j = 0; j <= i; j++){
            for(int k = 0; k < i - j; k++){
                Point ball1 = Point(i, k), ball2 = Point(i, k+1);
                int x1 = ball1.x, y1 = ball1.y;
                int x2 = ball2.x, y2 = ball2.y;

                if(b.at(x1).at(y1) > b.at(x2).at(y2)){
                    swap_balls(b, ball1, ball2, op1, op2);
                    K++;
                }
            }
        }

    }

    return;
}

int get_score(int N, vector<vector<int>> b, int K){
    int ret = -1;
    int E = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j <= i; j++){
            Point now_ball = Point(i, j);
            Point next_ball1 = Point(i+1, j), next_ball2 = Point(i+1, j+1);

            if(!is_correct_order(b, now_ball, next_ball1)){
                E++;
            }

            if(!is_correct_order(b, now_ball, next_ball2)){
                E++;
            }
        }
    }

    if(E == 0){
        ret = 100000 - 5*K;
    }
    else{
        ret = 50000 - 50*E;
    }

    assert(ret >= 0);
    return ret;
}

void output_func(int &K,vector<Point> &op1,vector<Point> &op2){
    cout << K << '\n';

    for(int i = 0; i < K; i++){
        Point p1 = op1.at(i), p2 = op2.at(i);
        cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << '\n';
    }

    return;
}


int main() {
    for(int i = 0; i < 1000; i++){
        int now = xRnd(1, 2);
        debugVL(now);
        assert(1 <= now && now <= 2);
    }

    return 0;
}