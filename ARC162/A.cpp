#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int T;
    cin >> T;
    while(T--){
        debugVL(T);

        int N;
        cin >> N;
        vector<int> P(N+1, -1);  // 1-indexed
        for(int i = 1; i <= N; i++){
            cin >> P.at(i);
        }

        bool all_same = true;
        int cnt = 0;
        priority_queue<int> pq;
        for(int i = 1; i <= N; i++){
            pq.push(i);
            cnt++;
        }
        for(int i = 1; i <= N; i++){
            if(P.at(i) <= i){
                while((!pq.empty()) && (pq.top() >= P.at(i))){
                    pq.pop();
                    cnt--;
                }

                pq.push(P.at(i));
                all_same = false;
                cnt++;
            }
        }

        if(all_same){
            cout << N << '\n';
        }
        else{
            cout << cnt << '\n';
        }
    }
}