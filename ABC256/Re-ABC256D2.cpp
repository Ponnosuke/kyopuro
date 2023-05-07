#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    vector<pair<i64, i64>> query;
    for(int i = 0; i < N; i++){
        i64 l, r;
        cin >> l >> r;
        query.push_back(make_pair(l, 0));  // ログイン処理を先にするために こっちを 0 に
        query.push_back(make_pair(r, 1));
    }

    sort(query.begin(), query.end()); // ここでさっきの 0 がいきる

    i64 cnt = 0;

    // 0 から 1以上の時刻と、 1 以上から 0 になった時刻を出力していく
    for(auto [t, f] : query){
        if(f == 0){
            if(cnt == 0) cout << t << " ";
            cnt++;
        }
        else{
            cnt--;
            if(cnt == 0) cout << t << endl;
        }
    }
}
