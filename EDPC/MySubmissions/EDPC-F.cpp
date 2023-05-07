#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(3010, vector<int>(3010, 0));
    // dp[i+1][j+1]  s の i (0-indexed) 文字目までと、t の j (0-indexed) 文字目までのLCSの最大値

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            if(s.at(i) == t.at(j)){
                dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j+1), dp.at(i).at(j) + 1);
            }

            dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j+1), dp.at(i).at(j+1));

            dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j+1), dp.at(i+1).at(j));
        }
    }

    string ans = "";
    int i = s.size(), j = t.size();
    while(i > 0 && j > 0){
        if(dp.at(i).at(j) == dp.at(i).at(j-1)){
            j--;
        }
        else if(dp.at(i).at(j) == dp.at(i-1).at(j)){
            i--;
        }
        else{
            ans = s.at(i-1) + ans;
            i--;
            j--;
        }
    }

    cout << ans << endl;

    return 0;
}