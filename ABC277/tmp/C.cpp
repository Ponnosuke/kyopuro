#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 POW9 = 1000000000LL;

int main() {
    i64 N;
    cin >> N;
    map<i64, vector<i64>> G;
    map<i64, i64> seen;  // v   0 : false,  1 : true
    for(int i = 0; i < N; i++){
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        seen[A] = 0;
        seen[B] = 0;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    queue<i64> Q;
    i64 ans = 0;
    Q.push(0);
    if(G.count(0)){
        seen.at(0) = 1;
    }
    else{
        cout << 1 << '\n';
        return 0;
    }

    // debug
    // cerr << "P29" << '\n';

    while(!Q.empty()){
        i64 v = Q.front();
        Q.pop();

        // debug
        // cerr << "v = " << v << '\n';
        // cerr << "P36" << '\n';

        if(G.count(v)){
            for(auto nv : G.at(v)){
                if(seen.at(nv) == 1){
                    continue;
                }

                seen.at(nv) = 1;

                ans = max(ans, nv);
                Q.push(nv);
            }
        }

        // debug
        // cerr << "P50" << '\n';
    }

    cout << ans + 1 << '\n';

    return 0;
}