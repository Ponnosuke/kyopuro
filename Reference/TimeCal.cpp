#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

clock_t startTime;
double getCurrentTime(){
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int main() {
    startTime = clock();
    cerr << fixed << setprecision(10);



    double now = getCurrentTime();
    cerr << now << endl;
    now = getCurrentTime();
    cerr << now << endl;

    return 0;
}