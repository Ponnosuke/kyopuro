#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int judge;
        cin >> judge;
        if(judge > 0) cnt++;
    }

    cout << cnt << endl;


}