#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<int> a(N), b(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i) >> b.at(i);
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));
    dp.at(0).at(0) = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= X; j++){
            if(dp.at(i).at(j)){
                if(j + a.at(i) <= X){
                    dp.at(i + 1).at(j + a.at(i)) = true;
                }
                if(j + b.at(i) <= X){
                    dp.at(i + 1).at(j + b.at(i)) = true;
                }
            }
        }
    }

    cout << (dp.at(N).at(X) ? "Yes" : "No") << "\n";

    return 0;
}