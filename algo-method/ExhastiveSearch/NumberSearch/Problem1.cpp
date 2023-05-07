#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        bool flag1 = (i % 2 != 0);
        bool flag2 = (i % 3 != 0);
        bool flag3 = (i % 5 != 0);

        if(flag1 && flag2 && flag3) cnt++;
    }

    printf("%d\n", cnt);
}