/*
円状の文字列に与えられた文字列が時計回り方向に存在するか
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  string s, p;
  cin >> s >> p;

  s += s;

  cout << (s.find(p) == -1 ? "No" : "Yes") << endl;
}
