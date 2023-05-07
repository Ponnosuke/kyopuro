#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N, -1);
    for(int i = 0; i < N; i++)  cin >> A.at(i);

    vector<i64> even, odd;
    bool evenExist = false, oddExist = false, OK = true;
    for(int i = 0; i < N; i++){
        if(A.at(i) % 2 == 0){
            even.push_back(A.at(i));
            evenExist = true;
        }
        else{
            odd.push_back(A.at(i));
            oddExist = true;
        }
    }

    if((N==2) && evenExist && oddExist){
        OK = false;
    }

    // debug
    // cout << "pointA" << endl;

    i64 ans = -1;
    if(OK){
        sort(even.begin(), even.end(), greater<i64>());
        sort(odd.begin(), odd.end(), greater<i64>());

        if(even.size() < 2){
            ans = odd.at(0) + odd.at(1);
        }
        else if(odd.size() < 2){
            ans = even.at(0) + even.at(1);
        }
        else{
            ans = max(even.at(0) + even.at(1), odd.at(0) + odd.at(1));
        }
    }

    cout << ans << '\n';
}