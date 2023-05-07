#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;
    
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++){
        bool isExist = false;

        for(auto ch : S){
            if(ch == c)  isExist = true;
        }

        if(isExist) ans++;
    }

    cout << ans << endl;
}