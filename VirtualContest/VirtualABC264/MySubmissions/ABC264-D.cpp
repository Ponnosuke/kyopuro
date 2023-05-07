#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    string str = "atcoder";
    vector<int> atc(S.size());

    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < str.size(); j++){
            if(S.at(i) == str.at(j))  atc.at(i) = j;
        }
    }

    // debug
    // for(auto c:atc)  cout << c << " ";

    int ans = 0;
    for(int i = 0; i < atc.size() - 1; i++){
        for(int j = 0; j < atc.size() - 1 - i ; j++){
            if(atc.at(j) > atc.at(j+1)){
                swap(atc.at(j), atc.at(j+1));
                ans++;
            }
        }
    }

    cout << ans << endl;
}