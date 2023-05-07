#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 1e7;

int main() {
    vector<string> S(10);
    for(int i = 0; i < 10; i++)  cin >> S.at(i);

    int A = INF, B = -INF, C = INF, D = -INF;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(S.at(i).at(j) == '#'){
                A = min(A, i + 1);
                B = max(B, i + 1);
                C = min(C, j + 1);
                D = max(D, j + 1);
            }
        }
    }

    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}