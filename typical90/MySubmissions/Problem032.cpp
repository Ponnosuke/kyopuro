#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }
    int M;
    cin >> M;
    vector<vector<bool>> rumor(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        rumor.at(x).at(y) = true;
        rumor.at(y).at(x) = true;
    }

    vector<int> ath(N);
    for(int i = 0; i < N; i++){
        ath.at(i) = i;
    }
    int ans = -1;
    do{
        bool OK = true;
        for(int i = 0; i < N-1; i++){
            if(rumor.at(ath.at(i)).at(ath.at(i+1))){
                OK = false;
                break;
            }
        }

        if(OK){
            int tmp = 0;
            for(int i = 0; i < N; i++){
                tmp += A.at(ath.at(i)).at(i);
            }

            if(ans == -1){
                ans = tmp;
            }
            else{
                ans = min(ans, tmp);
            }
        }
    }while(next_permutation(ath.begin(), ath.end()));

    cout << ans << '\n';
}