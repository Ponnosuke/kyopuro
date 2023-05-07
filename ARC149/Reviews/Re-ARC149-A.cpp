#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, M;
    cin >> N >> M;

    i64 num = -1, digits = 0;
    i64 rem;
    for(i64 i = 1; i <= 9; i++){

        rem = i % M;
        if(rem == 0){
            num = i;
            digits = 1;
        }

        for(i64 j = 0; j < N - 1; j++){

            rem = (10*rem + i) % M;
            if(rem == 0){
                if(digits <= j + 2){
                    num = i;
                    digits = j + 2;
                }
            }
        }
    }

    if(num == -1){
        cout << -1 << "\n";
    }
    else{
        for(int i = 0; i < digits; i++){
            cout << num;
        }
        cout << "\n";
    }

    return 0;
}