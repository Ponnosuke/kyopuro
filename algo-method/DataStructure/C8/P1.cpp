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
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for(int i = 1; i < N; i++){
        cin >> P.at(i);
    }
    vector<vector<int>> children(N);
    for(int i = 1; i < N; i++){
        children.at(P.at(i)).push_back(i);
    }

    // for(int i = 0; i < N; i++){
    //     sort(children.at(i).begin(), children.at(i).end());
    // }

    int Q;
    cin >> Q;
    while(Q--){
        int v;
        cin >> v;

        int par = P.at(v);

        int vSize = children.at(par).size();
        for(int i = 0; i < vSize; i++){
            cout << children.at(par).at(i);

            if(i < vSize - 1){
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}