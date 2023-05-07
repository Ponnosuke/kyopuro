#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // X と Y が違う方向
    if(X * Y < 0){
        cout << abs(X) << endl;
    }
    else if(abs(Y) > abs(X)){  // 壁がゴールより向こう
        cout << abs(X) << endl;
    }
    else if(Y * Z > 0){  // ハンマーと壁が同じ方向
        if(abs(Y) < abs(Z)){
            cout << -1 << endl;
        }
        else{
            cout << abs(X) << endl;
        }
    }
    else{  // ハンマーと壁が違う方向
        cout << 2 * abs(Z) + abs(X) << endl;
    }
}