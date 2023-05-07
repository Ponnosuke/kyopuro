#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  int h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

  vector<vector<int>> i1(800), i2(800), i3(800);  // 28 * 28

  int ans = 0;
  int ci1 = 0, ci2 = 0, ci3 = 0;
  for(int i = 1; i <= 28; i++){
    for(int j = 1; j + i <= 29; j++){
      if(h1 - i - j > 0){
        i1.at(ci1).push_back(i);
        i1.at(ci1).push_back(j);
        i1.at(ci1).push_back(h1 - i - j);
        // i1.at(ci1).push_back({i , j , h1 - i - j});
        ci1++;
      }
      if(h2 - i - j > 0){
        i2.at(ci2).push_back(i);
        i2.at(ci2).push_back(j);
        i2.at(ci2).push_back(h2 - i - j);
        // i2.at(ci2).push_back({i, j, h2 - i - j});
        ci2++;
      }
      if(h3 - i - j > 0){
        i3.at(ci3).push_back(i);
        i3.at(ci3).push_back(j);
        i3.at(ci3).push_back(h3 - i - j);
        // i3.at(ci3).push_back({i, j, h3 - i - j});
        ci3++;
      }
    }
  }

  ci1--;
  ci2--;
  ci3--;
  for(int i = 0; i <= ci1; i++){
    for(int j = 0; j <= ci2; j++){
      for(int k = 0; k <= ci3; k++){
        bool ok1 = (i1.at(i).at(0) + i2.at(j).at(0) + i3.at(k).at(0) == w1);
        bool ok2 = (i1.at(i).at(1) + i2.at(j).at(1) + i3.at(k).at(1) == w2);
        bool ok3 = (i1.at(i).at(2) + i2.at(j).at(2) + i3.at(k).at(2) == w3);
        if(ok1 && ok2 && ok3) ans++;
      }
    }
  }

  cout << ans << endl;

}
