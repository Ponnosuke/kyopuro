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
    vector<int> A(3*N, 0);
    for(int i = 0; i < 3*N; i++){
        cin >> A.at(i);
    }

    vector<int> cnt(N+1, 0);
    vector<int> idx(N+1, -1);  // [i] := f(i)
    for(int i = 0; i < 3*N; i++){
        int nowA = A.at(i);

        if(cnt.at(nowA) <= 1){
            cnt.at(nowA)++;
            if(cnt.at(nowA) == 2){
                idx.at(nowA) = i;
            }
        }
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i < N+1; i++){
        ans.emplace_back(idx.at(i), i);
    }
    sort(ans.begin(), ans.end());

    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans.at(i).second;

        if(i < (int)ans.size() - 1){
            cout << " ";
        }
    }
    cout << '\n';
}