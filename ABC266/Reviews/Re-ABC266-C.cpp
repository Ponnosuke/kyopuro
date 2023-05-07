#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

struct Point{
    int x, y;

    // コンストラクター 1 号
    Point(){}
    
    // コンストラクター 2 号
    Point(int ix, int iy){
        x = ix;
        y = iy;
    }

    Point operator - (Point p){
        return Point(x - p.x, y - p.y);
    }
    // コンストラクター 2 号を宣言していない場合は演算子オーバーロードを以下の書き方にする
    /*
    Point operator - (Point p){
        Point ret;
        ret.x = x - p.x;
        ret.y = y - p.y;

        return ret;
    }
    */
};

int cross(Point p, Point q){
    return p.x * q.y - p.y * q.x;
}

int main() {
    Point A;
    cin >> A.x >> A.y;
    Point B;
    cin >> B.x >> B.y;
    Point C;
    cin >> C.x >> C.y;
    Point D;
    cin >> D.x >> D.y;

    bool OK = true;
    if(cross(B-A, D-A) <= 0)  OK = false;  // 180度になることはないから = は必要ないっちゃ必要ない
    if(cross(C-B, A-B) <= 0)  OK = false;
    if(cross(D-C, B-C) <= 0)  OK = false;
    if(cross(A-D, C-D) <= 0)  OK = false;

    cout << (OK ? "Yes" : "No") << endl;
}