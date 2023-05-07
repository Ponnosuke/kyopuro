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

    // debug
    // for(int i = 0; i < N; i++){
    //     cout << p.at(i) << endl;
    // }

    int ans = -INF;
    for(int i = 0; i < N; i++){
        int iniIndex = i;
        int tmp = 0;

        // debug
        // cout << "i = " << i << endl;

        for(int j = 0; j < N; j++){\
            // int beforeIndex = (((iniIndex - 1 + j) % N) + N) % N;
            int nowIndex = (iniIndex + j) % N;
            // int afterIndex = (iniIndex + 1 + j) % N;
            bool OK1, OK2, OK3;
            OK1 = (p.at(nowIndex) == (((j - 1) % N) + N) % N);
            OK2 = (p.at(nowIndex)) == (j % N);
            OK3 = (p.at(nowIndex)) == ((j + 1) % N); 

            // debug
            // cout << "p = 人" << endl;
            // cout << p.at(beforeIndex) << " = " << ((((j - 1) % N) + N) % N) << endl;
            // cout << p.at(nowIndex) << " = " << (j % N) << endl;
            // cout << (p.at(afterIndex)) << " = " << ((j + 1) % N) << endl;
            // cout << "j = " << j << ", " << "bnaIndex = " << beforeIndex << nowIndex << afterIndex << ", p.at(nowIndex) = " << p.at(nowIndex) << endl;

            if(OK1 || OK2 || OK3) tmp++;
        }

        ans = max(ans, tmp);

        // debug
        // cout << "ans = " << ans << endl;
    }

    cout << ans << endl;
}