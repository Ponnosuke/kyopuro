#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> S(N);
    for(int i = 0; i < N; i++)  cin >> S.at(i);

    vector<i64> A;
    i64 now = 0;
    for(int i = 0; i < N; i++){
        i64 tmp = S.at(i) - now;
        A.push_back(tmp);
        now += tmp;
    }

    for(int i = 0; i < (int)A.size(); i++){
        cout << A.at(i);

        if(i < (int)A.size() - 1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}