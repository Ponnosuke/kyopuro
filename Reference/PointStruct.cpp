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

// 軽い動作確認済み。ただし、バグがある可能性あり。
struct Point{
    double x;
    double y;

    Point(double ix, double iy) :x(ix), y(iy) {
    }

    Point(){
    }

    void Set(double ix, double iy){
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
    Point operator *(const double &multNum){
        return Point(x * multNum, y * multNum);
    }
    Point operator /(const double &divNum){
        return Point(x / divNum, y / divNum);
    }
};

// 軽い動作確認済み、ただしバグがある可能性あり。
// rad は ラジアン なことに注意
Point pointRotate(Point P, double rad){
    return Point(P.x*cos(rad) - P.y*sin(rad), P.x*sin(rad) + P.y*cos(rad));
}

const double PI = acos(-1);

int main() {
    Point p1(2, 3), p2(3, 4);
    debugV((p1 + p2).x);
    debugVL((p1 + p2).y);
    debugV((p1 - p2).x);
    debugVL((p1 - p2).y);

    p1 = p1 * 5;
    p2 = p2 / 3;
    debugV(p1.x);
    debugVL(p1.y);
    debugV(p2.x);
    debugVL(p2.y);

    Point p3(1, 1);
    Point p4 = pointRotate(p3, PI / 2.0);
    debugV(p4.x);
    debugVL(p4.y);

    return 0;
}