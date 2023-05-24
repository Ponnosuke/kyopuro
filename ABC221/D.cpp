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
    vector<pair<int, int>> X;
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;

        X.emplace_back(A, 1);
        X.emplace_back(A+B, -1);
    }

    sort(X.begin(), X.end());
    int Xsize = X.size();

    vector<int> D(N+1, 0);
    int now = 1;
    for(int i = 1; i < Xsize; i++){
        D.at(now) += X.at(i).first - X.at(i-1).first;
        now += X.at(i).second;
    }

    for(int i = 1; i <= N; i++){
        cout << D.at(i);

        if(i < N){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}