#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    int tmp = N;

    vector<int> num(2, -1);
    for(int i = 0; i < 2; i++){
        num.at(i) = tmp % 16;
        tmp = tmp/16;
    }

    string table = "ABCDEF";

    // debug
    // cout << num.at(0) << endl;
    // cout << num.at(1) << endl;

    if(N < 16){
        cout << 0;
        if(N < 10){
            cout << N << endl;
            return 0;
        }
        else{
            cout << table.at(N - 10) << endl;
            return 0;
        }
    }
    else{
        if(num.at(1) < 10){
            cout << num.at(1);
        }
        else{
            cout << table.at(num.at(1) - 10);
        }
        
        if(num.at(0) < 10){
            cout << num.at(0) << endl;
        }
        else{
            cout << table.at(num.at(0) - 10) << endl;
        }

        return 0;
    }
}