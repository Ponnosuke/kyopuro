#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int cnt = 0;
    for(int num = 0; num <= 999; num++){
        vector<int> numVec = {((num/10)/10)%10, (num/10)%10, num % 10};
        int index = 2;
        for(int i = 0; i < N; i++){
            int STarget = S.at(i) - '0';
            if(STarget == numVec.at(index)){
                if(index == 0){
                    cnt++;
                    break;
                }

                index--;
            }
        }
    }

    cout << cnt << endl;
}