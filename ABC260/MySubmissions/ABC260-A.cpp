#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    bool flag01 = S.at(0) != S.at(1);
    bool flag12 = S.at(1) != S.at(2);
    bool flag20 = S.at(2) != S.at(0);

    if(flag01 && flag20){
        cout << S.at(0) << endl;
    }
    else if(flag12 && flag01){
        cout << S.at(1) << endl;
    }
    else if(flag12 && flag20){
        cout << S.at(2) << endl;
    }
    else{
        cout << -1 << endl;
    }

    
}