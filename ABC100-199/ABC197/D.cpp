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

    Point operator-(const Point &other){
        return Point(x - other.x, y - other.y);
    }
    Point operator+(const Point &other){
        return Point(x + other.x, y + other.y);
    }
};

const double PI = acos(-1);

int main() {
    // debug
    cerr << fixed << setprecision(20);

    int N;
    cin >> N;
    int x0, y0, xn2, yn2;
    cin >> x0 >> y0;
    cin >> xn2 >> yn2;

    Point p0(x0, y0), pn2(xn2, yn2);
    Point centerP = Point((p0.x + pn2.x) / 2.0, (p0.y + pn2.y) / 2.0);
    Point revVec = p0 - centerP;

    debugVL(PI);

    debugV(centerP.x);
    debugVL(centerP.y);
    debugV(revVec.x);
    debugVL(revVec.y);

    double theta = 2*PI / (double)N;
    
    debugVL(theta);

    debugV(cos(theta));
    debugVL(sin(theta));

    Point toVec = Point(revVec.x*cos(theta) - revVec.y*sin(theta), revVec.x*sin(theta) + revVec.y*cos(theta));
    Point p1 = centerP + toVec;

    debugV(toVec.x);
    debugVL(toVec.y);
    debugV(p1.x);
    debugVL(p1.y);

    cout << fixed << setprecision(19);
    cout << p1.x << " " << p1.y << endl;

    return 0;
}