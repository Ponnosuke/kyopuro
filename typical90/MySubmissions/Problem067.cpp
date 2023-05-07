#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string N;
    cin >> N;
    int K;
    cin >> K;

    if(N == "0"){
        cout << 0 << endl;
        return 0;
    }

    string N8 = N;
    for(int i = 0; i < K; i++){
        ui64 tmp = 1, N10 = 0;
        int index = N8.size() - 1;
        while(index >= 0){
            N10 += (N8.at(index) - '0') * tmp;
            tmp *= 8;
            index--;
        }

        string N9 = "";
        while(N10 > 0){
            if(N10 % 9 == 8){
                N9 = '5' + N9;
            }
            else{
                N9 = (char)((N10 % 9) + '0') + N9;
            }
            N10 /= 9;
        }

        N8 = N9;
    }

    cout << N8 << endl;

    return 0;
}