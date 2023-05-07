#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1000000000000000000000;

int main() {
    i64 a,b,c,d;
    cin >> a >> b >> c >> d;
    
    vector<i64> result(4);

    result.at(0) = a*c;
    result.at(1) = a*d;
    result.at(2) = b*c;
    result.at(3) = b*d;

    i64 ans = -INF;
    for(auto x:result){
        ans = max(ans, x);
    }

    cout << ans << endl;

}