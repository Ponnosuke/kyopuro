#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    int ans = 0, tmpCnt = 0;
    for(int i = 0; i < S.size() ; i++){
        bool isA = (S.at(i) == 'A');
        bool isC = (S.at(i) == 'C');
        bool isG = (S.at(i) == 'G');
        bool isT = (S.at(i) == 'T');
        
        if(isA || isC || isG || isT){
            tmpCnt++;
            ans = max(ans, tmpCnt);
        }
        else{
            tmpCnt = 0;
        }
    }

    cout << ans << endl;
}
