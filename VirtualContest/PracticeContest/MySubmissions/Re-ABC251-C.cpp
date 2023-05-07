#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    vector<i64> T(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i) >> T.at(i);
    }

    set<string> poem;

    int maxIndex = 0;
    for(int i = 0; i < N; i++){
        string tempS = S.at(i);
        i64 tempT = T.at(i);

        if(poem.count(tempS)){
            continue;
        }

        poem.insert(tempS);
        if(T.at(maxIndex) < tempT) maxIndex = i;
    }

    cout << maxIndex + 1 << endl;
}