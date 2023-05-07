#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<int> div;

    for(int i = max(A, B); i >= 1 ; i--){
        if((A%i == 0) && (B%i == 0)) div.push_back(i);
    }

    cout << div.at(K - 1) << endl;
}