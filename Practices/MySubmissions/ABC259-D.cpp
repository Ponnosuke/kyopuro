#include <bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

struct Circle{
    i64 x;
    i64 y;
    i64 r;

    Circle(){
    }

    Circle(i64 ix, i64 iy, i64 ir) : x(ix), y(iy), r(ir) {
    }

    void Set(i64 ix, i64 iy, i64 ir){
        x = ix;
        y = iy;
        r = ir;

        return;
    }
};

bool isConnected(Circle &C1, Circle &C2){
    i64 rSum = (C1.r + C2.r)*(C1.r + C2.r);
    i64 rdiff = (C1.r - C2.r)*(C1.r - C2.r);

    i64 dist = (C1.x - C2.x)*(C1.x - C2.x) + (C1.y - C2.y)*(C1.y - C2.y);

    if(rdiff <= dist && dist <= rSum){
        return true;
    }
    else{
        return false;
    }
    
}

bool isOnCircle(i64 ix, i64 iy, Circle C){
    i64 left = (ix - C.x)*(ix - C.x) + (iy - C.y)*(iy - C.y);
    i64 right = C.r * C.r;

    if(left == right){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int N;
    cin >> N;
    i64 sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    // vector<i64> x(N), y(N), r(N);
    vector<Circle> Cs(N, Circle());
    vector<int> startIndex, goalIndex;
    for(int i = 0; i < N; i++){
        // cin >> x[i] >> y[i] >> r[i];
        
        i64 x, y, r;
        cin >> x >> y >> r;

        Cs[i].Set(x, y, r);

        if(isOnCircle(sx, sy, Cs[i])){
            startIndex.push_back(i);
        }
        if(isOnCircle(tx, ty, Cs[i])){
            goalIndex.push_back(i);
        }
    }


    atcoder::dsu uf(N);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(isConnected(Cs[i], Cs[j])){
                uf.merge(i, j);
            }
        }
    }

    bool OK = false;
    for(int i = 0; i < startIndex.size(); i++){
        for(int j = 0; j < goalIndex.size(); j++){
            if(uf.same(startIndex[i], goalIndex[j])){
                OK = true;

                debugV(startIndex[i]);
                debugVL(goalIndex[j]);

                break;
            }
        }

        if(OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}