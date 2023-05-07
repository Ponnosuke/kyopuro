#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int tmpN = N;
    vector<int> num(2, -1);
    for(int i = 0; i < 2; i++){
        num.at(i) = tmpN % 16;
        tmpN /= 16;
    }

    string table = "0123456789ABCDEF";
    
    cout << table.at(num.at(1)) << table.at(num.at(0)) << endl;
}