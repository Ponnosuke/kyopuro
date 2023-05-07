#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  int N;
  cin >> N;

  vector<int> A(N+1,0);
  for(int i = 1; i <= N; i++) cin >> A.at(i);

  vector<int> mass(N+1,0); // コマがどのマスにあるか

  int P = 0;

  for(int i = 1; i<=N; i++){
    for(int j = 1; j <= i ; j++){
      mass.at(j) += A.at(i);
    }
  }

  for(int i =1; i <= N; i++){
    if(mass.at(i) >= 4) P++;
  }

  cout << P << endl;

}
