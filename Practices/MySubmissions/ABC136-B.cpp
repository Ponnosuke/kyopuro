#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        string str = to_string(i);
        if(str.size()%2 != 0){
            ans++;
        }
    }

    cout << ans << endl;
}