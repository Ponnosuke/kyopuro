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

void rec(int v, vector<vector<int>> &children, vector<int> &ans){
    for(int nv : children.at(v)){
        rec(nv, children, ans);
    }

    ans.push_back(v);
    
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 1; i <= N-1; i++){
        cin >> A.at(i);
    }

    vector<vector<int>> children(N);
    for(int i = 1; i <= N-1; i++){
        children.at(A.at(i)).push_back(i);
    }

    vector<int> ans;
    rec(0, children, ans);

    int ansSize = ans.size();
    for(int i = 0; i < ansSize; i++){
        cout << ans.at(i);

        if(i < ansSize - 1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}