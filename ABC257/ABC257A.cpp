#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  int N, X;
  cin >> N >> X;
  string str;
  for(int i = 0; i <= ('Z' - 'A'); i++){
    for(int j = 0; j < N; j++){
      str += (char)('A' + i);

      // debug
      // cout << (char)('A' + i);
    }

    // debug
    // cout << endl;
  }

  cout << str.at(X-1) << endl;
}
