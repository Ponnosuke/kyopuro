#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    bool flagY = false;
    for(int i = 0 ; i < N; i++){
        char S;
        cin >> S;
        if(S == 'Y')  flagY = true;
    }

    cout << (flagY ? "Four" : "Three") << endl;

}