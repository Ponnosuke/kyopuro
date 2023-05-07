#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<i64> B(2*N, 0);
    for(int i = 1; i < 2*N; i++){
        B.at(i) = B.at(i-1) + A.at((i-1) % N);
    }

    if((B.at(N) % 10LL) != 0){
        cout << "No" << '\n';
    }
    else{
        i64 tenth = B.at(N) / 10LL;
        bool OK = false;
        for(int i = 0; i < N; i++){
            i64 dest = B.at(i) + tenth;
            auto itr = lower_bound(next(B.begin(), i), B.end(), dest);
            if(itr == B.end()){
                continue;
            }
            else{
                if(*itr == dest){
                    OK = true;
                    break;
                }
            }
        }

        cout << (OK ? "Yes" : "No") << '\n';
    }

    return 0;
}