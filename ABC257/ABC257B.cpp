#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  int N,K,Q;
  cin >> N >> K >> Q;

  // 各コマの位置。数字はそのまま対応
  // 一番右に架空のコマを置いてストッパーにする
  vector<int> A(K + 2, 0);
  for(int i = 1; i <= K ; i++)  cin >> A.at(i);
  A.at(K + 1) = N + 1;

  vector<int> L(Q);
  for(int i = 0; i < Q; i++) cin >> L.at(i);

  for(auto num:L){
    if( A.at(num) + 1 < A.at(num + 1)){
      A.at(num)++;
    }
  }

  for(int i = 1; i <= K; i++){
    cout << A.at(i);
    if(i < K) cout << " ";
  }
  cout << endl;
}
