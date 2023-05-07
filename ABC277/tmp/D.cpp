#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N);
    i64 sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }

    sort(A.begin(), A.end());
    vector<i64> B = A;
    for(int i = 0; i < N; i++){
        B.push_back(A.at(i));
    }

    i64 diff = B.at(0), tmp = B.at(0), cnt = 1;
    for(int i = 0; i < 2*N - 1; i++){
        if(B.at(i) == B.at(i+1) || ((B.at(i) + 1) % M) == B.at(i+1) ){
            cnt++;
            if(cnt > N){
                diff = max(diff, tmp);
                tmp = B.at(i+1);
                cnt = 1;
            }
            else{
                tmp += B.at(i+1);
            }

            // debug
            // cerr << "routeA" << '\n';
            // cerr << tmp << '\n';
        }
        else{
            diff = max(diff, tmp);
            tmp = B.at(i+1);
            cnt = 1;

            // debug
            // cerr << "routeB" << '\n';
            // cerr << tmp << " " << diff << '\n';
        }
    }

    // debug
    // cerr << sum << " " << diff << '\n';

    i64 ans = sum - diff;
    cout << ans << endl;
}