/*
Wrong Answers

Input : 933555919616261 6
Output(WA)      9335559110000000
Output(Correct) 933555920000000
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 X = 933555919616261, K = 6;
    // cin >> X >> K;
    vector<i64> nums(17, 0);

    i64 tmp = X, keta = 0;
    cout << "Loop1\n";
    for(int i = 0; i < 16; i++){
        nums.at(i) = (tmp % 10);

        cout << "nums.at(" << i << ") = " << nums.at(i) << endl;

        tmp /= 10;
        if(tmp == 0){
            break;
        }
        else{
            keta++;
        }
    }

    cout << "\nLoop2\n";

    for(int i = 0; i < K; i++){
        cout << "i = " << i << endl;
        cout << "before: nums.at("<< i << ") = " << nums.at(i) << endl;
        if(nums.at(i) >= 5){
            cout << "routeA" << endl;
            nums.at(i) = 0;
            nums.at(i+1)++;
        }
        else{
            cout << "routeB" << endl;
            nums.at(i) = 0;
        }

        cout << "after:\n";
        cout << "nums.at(" << i << ") = " << nums.at(i) << endl;
        cout << "nums.at(" << i + 1 << ") = " << nums.at(i+1) << endl;
        cout << "\n";
    }

    int tmpK = K;
    while(nums.at(tmpK) > 9){
        nums.at(tmpK + 1)++;
        nums.at(tmpK) = 0;
        tmpK++;
    }

    if(nums.at(keta + 1) >= 1){
        keta++;
    }

    cout << "\n";

    cout << "Loop3\n";
    for(int i = keta; i >= 0; i--){
        cout << "nums.at(" << i << ") = " << nums.at(i) << endl;
    }
}