#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for(int i = 0; i < S.size() - 2; i++){
        bool flag1 = (S.at(i) == 'A');
        bool flag2 = (S.at(i+1) == 'B');
        bool flag3 = (S.at(i+2) == 'C');

        if(flag1 && flag2 && flag3) ans++;
    }

    cout << ans << endl;
}
