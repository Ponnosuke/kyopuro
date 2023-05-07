#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<int> input(3);
    for(int i = 0; i < 3; i++){
        cin >> input.at(i);
    }
    bool OK1 = false, OK2 = false, OK3 = false;
    for(int i = 0; i < 3; i++){
        int tmp = input.at(i);
        if(tmp == 5 && OK1){
            OK3 = true;
        }
        if(tmp == 7){
            OK2 = true;
        }
        if(tmp == 5){
            OK1 = true;
        }
    }

    bool OK = OK1 && OK2 && OK3;
    cout << (OK ? "YES" : "NO") << endl;
}