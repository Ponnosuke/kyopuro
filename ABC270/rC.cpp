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
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int U, V;
        cin >> U >> V;
        U--;
        V--;

        G.at(U).push_back(V);
        G.at(V).push_back(U);
    }

    debugP();

    vector<int> recFrom(N, -1);
    queue<int> Q;
    Q.push(X);
    vector<bool> seen(N, false);
    // seen.at(X) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        seen.at(v) = true;
        
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            Q.push(nv);
            recFrom.at(nv) = v;
        }
    }

    debugP();

    vector<int> ans;
    int now = Y;
    ans.push_back(now);
    debugVL(now);
    while(now != X){
        now = recFrom.at(now);
        ans.push_back(now);

        debugVL(now);
    }

    reverse(ans.begin(), ans.end());

    debugP();

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i) + 1;

        if(i < ans.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}