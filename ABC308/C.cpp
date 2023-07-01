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
    ui64 N;
    cin >> N;
    vector<ui64> A(N), B(N);
    for(ui64 i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    // ui64 L = (A.at(0) + B.at(0));
    // for(ui64 i = 0; i < N; i++){
    //     L = lcm(L, A.at(i) + B.at(i));

    //     debugV(i);
    //     debugVL(L);
    //     assert(L <= ((1LL << 60) - 1 + (1LL << 60)));
    // }

    vector<int> ans;
    for(int i = 0; i < N; i++){
        ans.push_back(i);
    }

    auto myGreater = [&](int i, int j){
        ui64 L = lcm(A.at(i) + B.at(i), A.at(j) + B.at(j));
        ui64 val_i = A.at(i) * (L / (A.at(i) + B.at(i)));
        ui64 val_j = A.at(j) * (L / (A.at(j) + B.at(j)));
        if(val_i == val_j){
            return i < j;
        }
        else{
            return val_i > val_j;
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