#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  i64 N;
  string S;
  cin >> N >> S;

  vector<pair<i64, char>> P(N);
  i64 ans = 0;
  for(int i = 0; i < N; i++){
    cin >> P.at(i).first;
    P.at(i).second = S.at(i);
    if(P.at(i).second == '1')  ans++;
  }

  sort(P.begin(), P.end());

  i64 tmp = ans;
  for(int i = 0; i < N ; i++){
    if(P.at(i).second == '0'){
        tmp++;
    }
    else{
        tmp--;
    }

    if(i < N-1){
        if(P.at(i).first != P.at(i + 1).first)  ans = max(ans, tmp);
    }
    else{
        ans = max(ans, tmp);
    }
  }

  cout << ans << endl;
}
