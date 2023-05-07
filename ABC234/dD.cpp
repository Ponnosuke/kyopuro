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

// WA
vector<int> solve1(int N, int K, vector<int> &P){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        if(i+1 >= K){
            if(pq.empty()){
                pq.emplace(P.at(i));    
            }

            if(pq.top() < P.at(i)){
                pq.emplace(P.at(i));
            }
            // pq.size() が K未満の時、この条件式が成立しないと、pq.size() が K に足りていないのに
            // pq に P が追加されないことになって この後K番目に大きい数を満たせなくなる

            while(pq.size() > K){
                pq.pop();
            }

            ans.emplace_back(pq.top());
        }
        else{
            pq.emplace(P.at(i));
        }
    }

    return ans;
}

// AC
vector<int>  solve2(int N, int K, vector<int> &P){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(i+1 == K){
            pq.emplace(P.at(i));
            ans.emplace_back(pq.top());
        }
        else if(i+1 > K){
            if(pq.top() < P.at(i)){
                pq.emplace(P.at(i));
                pq.pop();
            }

            ans.emplace_back(pq.top());
        }
        else{
            pq.emplace(P.at(i));
        }
    }

    return ans;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N, 0);
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }

    cerr << N << " " << K << '\n';
    for(int i = 0; i < N; i++){
        cerr << P.at(i);
        if(i < N-1){
            cerr << " ";
        }
    }
    cerr << '\n';

    vector<int> sol1 = solve1(N, K, P), sol2 = solve2(N, K, P);
    if(sol1 != sol2){
        cerr << "Wrong!" << '\n';
        cerr << "sol1:" << '\n';
        for(int x : sol1){
            cerr << x << " ";
        }
        cerr << '\n';
        cerr << "sol2:" << '\n';
        for(int x : sol2){
            cerr << x << " ";
        }
        cerr << '\n';
    }

    return 0;
}