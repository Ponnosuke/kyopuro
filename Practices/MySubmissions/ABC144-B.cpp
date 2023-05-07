#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    bool OK = false;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i*j == N){
                OK = true;
                break;
            }
        }
        if(OK) break;
    }

    cout << (OK ? "Yes" : "No") << endl;
}
