#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> hasAttended(N);
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            x--;
            hasAttended.at(x).insert(i);
        }
    }

    bool OK = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;

            bool OK1 = false;
            for(int k = 0; k < M; k++){
                if(hasAttended.at(i).count(k) && hasAttended.at(j).count(k)){
                    OK1 = true;
                }
            }
            if(!OK1){
                OK = false;
            }
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}