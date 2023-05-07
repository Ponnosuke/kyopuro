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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<int> color(N, -1);
    queue<int> Q;
    bool OK = true;
    for(int i = 0; i < N; i++){
        if(color.at(i) != -1){
            continue;
        }

        color.at(i) = 1;
        Q.push(i);
        while(!Q.empty()){
            int v = Q.front();
            debugVL(v);
            Q.pop();
            for(int nv : G.at(v)){
                if(color.at(nv) != -1){
                    if(color.at(nv) == color.at(v)){
                        OK = false;
                        break;
                    }
                }
                else{
                    color.at(nv) = 1 - color.at(v);
                    Q.push(nv);
                }
            }

            if(!OK){
                break;
            }
        }

        if(!OK){
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}