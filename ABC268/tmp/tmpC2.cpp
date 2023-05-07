#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 10000000;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i = 0; i < N; i++)  cin >> p.at(i);

    int ans = -INF;
    for(int i = 0; i < N; i++){
        int iniIndex = i;
        int tmp = 0;

        for(int j = 0; j < N; j++){\
            int nowIndex = (iniIndex + j) % N;
            bool OK1, OK2, OK3;
            OK1 = (p.at(nowIndex) == (((j - 1) % N) + N) % N);
            OK2 = (p.at(nowIndex)) == (j % N);
            OK3 = (p.at(nowIndex)) == ((j + 1) % N); 
            if(OK1 || OK2 || OK3) tmp++;
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}