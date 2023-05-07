#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, L;
    cin >> N >> L;
    vector<int> a(N);
    for(auto &x : a){
        cin >> x;
    }

    i64 now = 0;
    bool OK = true;
    for(int i = 0; i < N; i++){
        if(a.at(i) == 1){
            now += 2;
            continue;
        }

        if(a.at(i) == 2){
            if(L - now < 2){
                OK = false;
                break;
            }
            else{
                now += 3;
            }
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}