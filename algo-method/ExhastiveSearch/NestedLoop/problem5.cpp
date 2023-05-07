#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

bool isPalin(string str){
    bool OK = true;
    for(int i = 0; i < str.size(); i++){
        if(str.at(i) != str.at(str.size() - 1 - i)){
            OK = false;
            break;
        }
    }

    return OK;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(auto &str : S)  cin >> str;

    int ans = 0;
    for(auto str : S){
        if(isPalin(str))  ans++;
    }

    cout << ans << endl;

}