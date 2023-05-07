#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    i64 N;
    cin >> N;
    vector<i64> a(N+1, 0);
    for(i64 i = 0; i < N; i++){
        cin >> a.at(i);
    }

    queue<i64> Q;
    i64 ans = 0;
    for(i64 ele : a){

        // 次の数を入れていい状態になるまで Q を整理
        if(!Q.empty()){
            if(Q.back() >= ele){
                i64 len = Q.size();
                ans += (len * (len + 1)) / 2;
                debugV(len);
                debugVL(ans);

                while(!Q.empty()){
                    Q.pop();
                }
            }

        }

        Q.push(ele);
    }

    cout << ans << endl;
}