#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;


int counter = 0;

// The original of this function is created by take_o. I edited it a little.
void Combination(vector<int> v, int n, int r, int vIndex, vector<int> temp, int tempIndex) {
    temp.at(tempIndex) = vIndex;
    if (tempIndex < r - 1) return Combination(v, n, r, vIndex + 1, temp, tempIndex + 1);
    for (int i = 0; i < temp.size(); i++) {
        cout << temp.at(i) + 1 << " ";
    }
    cout << endl;
    counter += 1;
    if (temp.at(0) == n - r) return;
    if (vIndex == v.size() - 1) {
        for (int i = r - 1, j = n - 1; i >= 0; i--, j--) {
            if (temp[i] < j) return Combination(v, n, r, temp.at(i) + 1, temp, i);
        }
    }
    return Combination(v, n, r, vIndex + 1, temp, tempIndex);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> fromVec(M); 
    iota(fromVec.begin(), fromVec.end(), 1);
    vector<int> outVec(N);
    Combination(fromVec, M, N, 0, outVec, 0);

    return 0;
 
}