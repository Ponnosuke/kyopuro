/*
入力の記号とかを EOF まで読み込み
char ch;

while ( cin >> ch ){
  処理
}
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  char c;
  vector<int> count(26, 0); // アルファベットの種類数

  while(cin >> c){
    if('A' <= c && c <= 'Z') c = (char)tolower(c);  // 読み込んだ文字が大文字だったら小文字に変換
    if('a' <= c && c <= 'z'){
      count.at(c - 'a')++;
    }
  }
  
  // アルファベット : そのアルファベットの個数 で出力
  for(int i = 0; i < 26; i++){
  cout << (char)('a' + i) << " : " << count.at(i) << endl;
  }

  return 0;
}
