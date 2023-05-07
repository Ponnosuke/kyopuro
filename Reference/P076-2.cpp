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
            i64 left = i-1, right = (i64)B.size();
            while(right - left > 1){
                i64 mid = left + (right - left) / 2;

                if(B.at(mid) >= (dest)){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }

            if(right == (i64)B.size()){
                continue;
            }
            else{
                if(dest == B.at(right)){
                    OK = true;
                    break;
                }
            }
        }

        cout << (OK ? "Yes" : "No") << '\n';
    }

    return 0;
}