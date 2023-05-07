/*
    The original from:
    提出 #28762082 - AtCoder Beginner Contest 236 
    https://atcoder.jp/contests/abc236/submissions/28762082 
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int n, n2;
vector<vector<int>> a;
int ans;
void dfs(vector<bool> s, int x) {
  int si = -1;
  rep(i,n2) if (!s[i]) { si = i; break;}
  if (si == -1) {
    ans = max(ans, x);
    return;
  }

  s[si] = true;
  rep(i,n2) if (!s[i] && si != i) {
    debugV(si);
    debugVL(i);
    s[i] = true;
    dfs(s, x^a[si][i]);
    s[i] = false;
  }
}

int main() {
  cin >> n;
  n2 = n*2;
  a = vector<vector<int>>(n2, vector<int>(n2));
  rep(i,n2) {
    for (int j = i+1; j < n2; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }

  vector<bool> s(n2);
  dfs(s,0);

  cout << ans << endl;
  return 0;
}