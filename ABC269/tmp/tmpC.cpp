#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    vector<int> Keta(15, -1);
    int num = 0, index = 0;
    while(N > 0){
        if(N % 2 == 1){
            Keta.at(index) = num;
            index++;
        }
        N /= 2;
        num++;
    }

    for(int tmp = 0; tmp < (1 << index); tmp++){
        bitset<15> bitS(tmp);

        i64 ans = 0;
        for(int i = 0; i < index; i++){
            if(bitS.test(i)){
                ans += ((i64)1 << Keta.at(i));
            }
        }

        cout << ans << endl;
    }
}