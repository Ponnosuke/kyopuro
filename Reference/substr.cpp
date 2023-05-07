// Reference  ABC150-B
/*
string S;
cin >> S;

S.substr(N) : 文字列 S の N文字目から最後の文字までの部分文字列を返すFunction
  インデックスは 0 から数える

S.substr(N, r) : 文字列 S の N文字目から N + r - 1 文字目までの部分文字列を返すfunction
  N文字目を含めて r文字取り出す
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S = "Ponnosuke";

    cout << S.substr(4) << endl;  // osuke
    cout << S.substr(3, 4) << endl;  // nosu
}
