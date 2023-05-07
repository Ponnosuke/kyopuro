#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    int ans = 0;
    for(int m = 1; m <= N; m++){
        vector<int> vec(N, 1);

        // debug
        // cerr << "m = " << m << '\n';
        // cerr << "point20\n"; 

        for(int i = 0; i < m; i++){
            vec.at(i) = 0;
        }

        // debug
        // cerr << "point27\n";

        do{
            int cnt = 0;
            map<char, int> mp;
            for(int i = 0; i < N; i++){
                if(vec.at(i) == 0){
                    for(auto ch : S.at(i)){
                        mp[ch]++;
                    }
                }
            }

            for(auto [p, q] : mp){
                if(q == K){
                    cnt++;
                }
            }
            
            ans = max(ans, cnt);
        }while(next_permutation(vec.begin(), vec.end()));
    }

    // debug
    // cerr << "point51\n";

    cout << ans << '\n';
}