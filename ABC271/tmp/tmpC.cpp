// This is WA.

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    vector<i64> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());

    // debug
    // for(int i = 0; i < N; i++){
    //     cout << a.at(i) << endl;
    // }

    deque<i64> deq;
    for(int i = 0; i < N; i++){
        deq.push_back(a.at(i));
    }

    // debug
    // cout << deq.front() << endl;

    i64 kan = 1;
    i64 now = -1;

    // debug
    // cout << "pointA" << endl;

    while(true){
        now = deq.front();

        if(now == kan){
            deq.pop_front();
            kan++;
        }
        else{
            if(deq.size() >= 2){
                deq.pop_back();
                deq.pop_back();
                kan++;
            }
            else{
                break;
            }
        }
    }

    kan--;

    cout << kan << endl;
}