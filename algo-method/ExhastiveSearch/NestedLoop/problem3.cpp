#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int L, R;
    cin >> L >> R;

    int ans = 0;
    for(int i = L; i <= R; i++){
        string str = to_string(i);
        
        if(str.size() == 1){
            ans++;
            continue;
        }

        bool isPalin = true;
        for(int i = 0; i < str.size(); i++){
            char leftC = str.at(i), rightC = str.at(str.size() - 1 - i);
            if(leftC != rightC){
                isPalin = false;
                break;
            }
        }

        if(isPalin) ans++;
    }

    cout << ans << endl;

    return 0;
}