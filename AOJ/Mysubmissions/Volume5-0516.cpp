#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 1e8;

int main() {
    while(true){
        int n, k;
        cin >> n >> k;
        if((n == 0) && (k == 0))  break;

        vector<int> a(n), b(n+1, 0);
        for(int i = 0; i < n; i++){
            cin >> a.at(i);
            b.at(i+1) = b.at(i) + a.at(i);
        }

        int ans = -INF;
        for(int i = 0; i < n - k + 1; i++){
            int tmp = b.at(i+k) - b.at(i);
            ans = max(ans, tmp);
        }

        cout << ans << endl;
    }

    return 0;
}