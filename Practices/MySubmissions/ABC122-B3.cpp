#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    string checkStr = "ACGT";

    int ans = 0, now = 0;
    for(int i = 0; i < S.size() ; i++){
        bool isACGT = false;
        for(int j = 0; j < checkStr.size(); j++){
            if(S.at(i) == checkStr.at(j))  isACGT = true;
        }

        if(isACGT){
            now++;
            ans = max(ans, now);
        }
        else{
            now = 0;
        }
    }

    cout << ans << endl;
}