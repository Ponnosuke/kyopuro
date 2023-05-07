#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1000000000;

int main() {
    i64 A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    i64 sum = INF, maxCnt = max(X,Y);

    for(int i = 0; i/2 <= maxCnt; i++){
        i64 ABCnt = i;
        i64 XCnt, YCnt;
        if(X - i/2 >= 0){
            XCnt = X - i/2;
        }
        else{
            XCnt = 0;
        }
        if(Y - i/2 >= 0){
            YCnt = Y - i/2;
        }
        else{
            YCnt = 0;
        }

        i64 now = A*XCnt + B*YCnt + C*ABCnt;

        sum = min(sum, now);
    }

    cout << sum << endl;
}