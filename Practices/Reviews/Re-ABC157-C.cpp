#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> s(M), c(M);
    for(int i = 0; i < M; i++){
        cin >> s.at(i) >> c.at(i);
        s.at(i)--;
    }

    int ans = -1;
    for(int num = 0; num <= 999; num++){
        string str = to_string(num);

        if(N != str.size())  continue;

        bool OK = true;
        for(int i = 0; i < M; i++){
            if((str.at(s.at(i)) - '0') != c.at(i)){
                OK = false;
                break;
            }
        }

        if(OK){
            ans = num;
            break;
        }
    }

    cout << ans << endl;
}