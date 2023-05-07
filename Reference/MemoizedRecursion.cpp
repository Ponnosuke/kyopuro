/*
    メモ化再帰

    ABC247-C
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

map<int, string> memo;

string S(int n){
    if(memo.count(n)){
        return memo.at(n);
    }

    string ret;

    if(n == 1){
        ret = "1";
    }
    else{
        ret = S(n-1) + " " + to_string(n) + " " + S(n-1);
    }

    memo[n] = ret;

    return ret;
}

int main() {
    int N;
    cin >> N;
    string ans;
    ans = S(N);

    cout << ans << "\n";
}