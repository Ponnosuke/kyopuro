#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    map<string, int> S;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        if(S.count(str)){
            S[str]++;
            cout << str << '(' << S.at(str) << ')' << endl;;
        }
        else{
            S[str] = 0;
            cout << str << endl;
        }
    }
}