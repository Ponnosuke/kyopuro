#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    double A, B;
    cin >> A >> B;
    string str = to_string(B / A);
    for(int i = 0; i < 4; i++){
        cout << str.at(i);
    }

    int num = str.at(4) - '0';
    int checkNum = str.at(5) - '0';
    if(checkNum >= 5){
        cout << num + 1 << endl;
    }
    else{
        cout << num << endl;
    }
}