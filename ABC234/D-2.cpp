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
    int N, K;
    cin >> N >> K;
    vector<int> P(N, 0);
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        if(i+1 == K){
            pq.emplace(P.at(i));
            cout << pq.top() << '\n';
        }
        else if(i+1 > K){
            if(pq.top() < P.at(i)){
                pq.emplace(P.at(i));
                pq.pop();
            }

            cout << pq.top() << '\n';
        }
        else{
            pq.emplace(P.at(i));
        }
    }

    return 0;
}