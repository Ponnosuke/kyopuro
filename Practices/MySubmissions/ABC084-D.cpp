#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int MAX = 1e6;

int main() {
    int Q;
    cin >> Q;

    vector<int> isPrime(MAX, 1);  // 1 -> true, 0 -> false
    isPrime.at(0) = 0;
    isPrime.at(1) = 0;

    // 素数ふるい
    for(int i = 2; i < MAX; i++){
        if(isPrime.at(i) == 1){
            for(int j = i * 2; j < MAX; j += i){
                isPrime.at(j) = 0;
            }
        }
    }

    vector<int> like2017(MAX, 0); // 1 true, 0 false
    for(int i = 0; i < MAX; i++){
        if(i%2 == 0)  continue;

        bool OK1 = (isPrime.at(i) == 1);
        bool OK2 = (isPrime.at((i+1)/2) == 1);

        if(OK1 && OK2)  like2017.at(i) = 1;

    }

    // 累積和
    vector<int> S(MAX + 1, 0);
    for(int i = 0; i < MAX; i++){
        S.at(i+1) = S.at(i) + like2017.at(i);
    }

    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        r++;

        // debug
        // for(int j = 0; j < r; j++){
        //     cout << "isPrime.at(" << j << ") = " << isPrime.at(j) << endl;
        // }
        // for(int j = 0; j < r + 1; j++){
        //     cout << "S.at(" << j << ") = " << S.at(j) << endl;
        // }
        // cout << "S.at(" << r << ") - S.at(" << l << ") = ";

        cout << S.at(r) - S.at(l) << endl;
    }

    return 0;
}