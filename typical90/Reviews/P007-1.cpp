#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 MAX_AB = 1000000000;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N + 2, 0);
    A.at(0) = -(2*MAX_AB) - 100;
    for(int i = 1; i < N + 1; i++){
        cin >> A.at(i);
    }
    A.at(N+1) = 2*MAX_AB + 100;
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
        cout << min(abs(*itr - B.at(i)), abs(*prev(itr) - B.at(i))) << '\n';

        // debug
        // cerr << "*itr = " << *itr << ", *prev(itr) = " << *prev(itr) << ", B.at(" << i << ") = " << B.at(i) << '\n';

    }

    return 0;
}