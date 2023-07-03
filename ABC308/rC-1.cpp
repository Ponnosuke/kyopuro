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
    i64 N;
    cin >> N;
    vector<i64> A(N), B(N);
    for(i64 i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    vector<int> ans;
    for(int i = 0; i < N; i++){
        ans.push_back(i);
    }

    auto myGreater = [&](int i, int j){
        i64 val_L = A.at(i) * (A.at(j) + B.at(j));
        i64 val_R = A.at(j) * (A.at(i) + B.at(i));
        if(val_L == val_R){
            return i < j;
        }
        else{
            return val_L > val_R;
        }
    };

    sort(ans.begin(), ans.end(),  myGreater);

    for(int i = 0; i < N; i++){
        cout << ans.at(i) + 1;
        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
}