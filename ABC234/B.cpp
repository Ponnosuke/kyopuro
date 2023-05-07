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
    int x, y;

    Point(int ix, int iy) : x(ix), y(iy) {
    }

    Point(){
    }
};

double calDist(Point p1, Point p2){
    double x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;

    return hypot(x1 - x2, y1 - y2);
}

int main() {
    int N;
    cin >> N;
    vector<Point> P(N, Point());
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        P.at(i) = Point(x, y);
    }

    double ans = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Point p1 = P.at(i), p2 = P.at(j);

            ans = max(ans, calDist(p1, p2));
        }
    }

    cout << fixed << setprecision(16);
    cout << ans << endl;
}