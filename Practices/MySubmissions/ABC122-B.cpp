#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    int ans = 0;
    for(int i = 0; i < S.size() ; i++){
        int tmpCnt = 0;
        int j = i;
        while(true){
            bool isA = (S.at(j) == 'A');
            bool isC = (S.at(j) == 'C');
            bool isG = (S.at(j) == 'G');
            bool isT = (S.at(j) == 'T');
            
            if(isA || isC || isG || isT){
                tmpCnt++;
            }
            else{
                break;
            }
            
            j++;
            if(j >= S.size())  break;
        }

        ans = max(ans, tmpCnt);
    }

    cout << ans << endl;
}
