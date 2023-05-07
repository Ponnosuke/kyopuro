#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int K;
    cin >> K;

    int H, M;
    H = K/60;
    H += 21;
    M = K%60;

    string hour, minute;

    hour = to_string(H);
    minute = to_string(M);

    if(hour.size() == 1) hour = '0' + hour;
    if(minute.size() == 1) minute = '0' + minute;

    cout << hour << ":" << minute << endl;
}