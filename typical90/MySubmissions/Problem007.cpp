#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int Q;
    cin >> Q;
    vector<i64> B(Q);
    for(int i = 0; i < Q; i++){
        cin >> B.at(i);
    }

    sort(A.begin(), A.end());

    // debug
    // cerr << "A: ";
    // for(auto x : A)  cerr << x << " ";
    // cerr << '\n';

    for(int i = 0; i < Q; i++){

        // debug
        // cerr << "i = " << i << '\n';

        auto itr = upper_bound(A.begin(), A.end(), B.at(i));
        if(itr == A.end()){
            cout << abs(*prev(itr) - B.at(i)) << '\n';

            // debug
            // cerr << "pointA" << '\n';
            // cerr << "*prev(itr) = " << *prev(itr) << ", B.at(" << i << ") = " << B.at(i) << '\n';
        
        }
        else if(itr == A.begin()){
            cout << abs(*itr - B.at(i)) << '\n';
        }
        else{
            cout << min(abs(*itr - B.at(i)), abs(*prev(itr) - B.at(i))) << '\n';

            // debug
            // cerr << "pointB" << '\n';
            // cerr << "*itr = " << *itr << ", *prev(itr) = " << *prev(itr) << ", B.at(" << i << ") = " << B.at(i) << '\n';

        }
    }

    return 0;
}