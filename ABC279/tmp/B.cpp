#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S, T;
    cin >> S >> T;

    bool OK = false;
    int j = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == T.at(j)){
            if(j == T.size() - 1){
                OK = true;
                break;
            }
            j++;
        }
        else{
            j = 0;
        }
    }

    cout << (OK ? "Yes" : "No") << endl;
}