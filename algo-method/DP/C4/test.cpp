#include<iostream>
#include<vector>
using namespace std;

int main() {
    // 入力を受け取る
    int M, N; cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(N));
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    // DP テーブルと初期化に使う大きな数
    const int INF = 1<<30;
    vector<vector<int>> dp(N+1, vector<int>(1<<M, INF));

    // 0 ~ 2^M-1 の塗り方のうち、条件を満たさない塗り方をあらかじめ調べておく
    vector<bool> is_ban(1<<M, false);
    for(int bit = 0; bit < 1<<M; ++bit) {
        for(int i = 0; i < M-1; ++i) {
            if((bit & 1<<i) == 0 && (bit & 1<<(i+1)) == 0) {is_ban[bit] = true;}
        }
    }

    // i 行目を塗り方 p で塗るときの、黒マスに書かれた総和
    vector<vector<int>> sum_Acol(N, vector<int>(1<<M, 0));
    for(int i = 0; i < N; ++i) {
        for(int p = 0; p < 1<<M; ++p) {
            int sum = 0;
            for(int j = 0; j < M; ++j) {
                if(p & 1<<j) {sum += A[j][i];}
            }
            sum_Acol[i][p] = sum;
        }
    }

    // DP 初期条件
    int full = (1<<M) - 1;  // M 行すべて黒く塗るときの塗り方に対応する番号
    dp[0][full] = 0;

    // 0 := white,  1 := black

    // DP テーブルの更新
    for(int i = 0; i < N; ++i) {
        for(int p = 0; p < 1<<M; ++p) {
            // i 行目の塗り方 p が条件に反する塗り方ならば、スキップ
            if(is_ban[p]) {continue;}

            for(int bit1 = 0; bit1 < 1<<M; ++bit1) {
                // i-1 行目の塗り方 bit1 が条件に反する塗り方ならば、スキップ
                if(is_ban[bit1]) {continue;}

                // p OR bit1 が 11…1 ならば、dp[i][p] を更新する
                if((p | bit1) == full) {
                    dp[i+1][p] = min(dp[i+1][p], dp[i][bit1] + sum_Acol[i][p]);
                }
            }
        }
    }
    
    // 答えを出力する
    int ans = INF;
    for(int p = 0; p < 1<<M; ++p) {
        ans = min(ans, dp[N][p]);
    }
    cout << ans << endl;

    return 0;
}