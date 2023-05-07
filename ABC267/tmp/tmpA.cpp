#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    int tmp = 0;
    if(S == "Monday")  tmp = 0;
    else if(S == "Tuesday") tmp = 1;
    else if(S == "Wednesday")  tmp = 2;
    else if(S == "Thursday")  tmp = 3;
    else  tmp = 4;

    cout << 5 - tmp << endl;
}