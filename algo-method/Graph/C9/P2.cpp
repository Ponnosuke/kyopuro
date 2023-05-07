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
    int N, s, K;
    cin >> N >> s >> K;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
        G.at(b).emplace_back(a);
    }

    set<int> se;
    se.insert(s);
    for(int i = 0; i < K; i++){
        set<int> tmp;
        swap(se, tmp);
        
        for(auto ele : tmp){
            for(auto nx : G.at(ele)){
                se.insert(nx);
            }
        }
    }

    cout << se.size() << endl;
}