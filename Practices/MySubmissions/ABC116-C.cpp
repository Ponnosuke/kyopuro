#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> h(N+1, 0);
    for(int i = 1; i <= N; i++)  cin >> h.at(i);

    vector<int> flower(N+1, 0);  // 花0 を仮想的に用意する
    vector<bool> hasGrown(N+1, false); // hasGronwn[i]  花i が指定の高さか否か
    hasGrown.at(0) = true;
    for(int i = 1; i <= N; i++){
        if(h.at(i) == 0)  hasGrown.at(i) = true;
    }

    i64 ans = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j <= N; j++){
            if(hasGrown.at(j)){
                if(j < N){
                    if(!hasGrown.at(j+1)){
                        ans++;
                    }
                }
            }
            else{
                flower.at(j)++;
                if(flower.at(j) == h.at(j)){
                    hasGrown.at(j) = true;
                }
            }
        }

        // debug
        // for(int k = 0; k <= N; k++){
        //     cout << flower.at(k);
        //     if(k < N)  cout << " ";
        //     else cout << endl;
        // }
    }

    cout << ans << endl;
}