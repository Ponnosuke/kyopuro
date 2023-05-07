#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    set<string> mySet;
    for(int i = 0; i < N; i++){
        if(mySet.count(S.at(i))){
            continue;
        }
        else{
            cout << i + 1 << "\n";
            mySet.insert(S.at(i));
        }
    }

    return 0;
}