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
    vector<int> A(N), B(N);
    vector<int> X;
    for(int i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
        X.push_back(A.at(i));
        X.push_back(A.at(i) + B.at(i));
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    int Xsize = X.size();
    vector<int> table(Xsize, 0);
    for(int i = 0; i < N; i++){
        int L = distance(X.begin(), lower_bound(X.begin(), X.end(), A.at(i)));
        int R = distance(X.begin(), lower_bound(X.begin(), X.end(), A.at(i) + B.at(i)));

        table.at(L)++;
        table.at(R)--;
    }

    for(int i = 0; i < Xsize - 1; i++){
        table.at(i+1) += table.at(i);
    }

    vector<int> D(N+1, 0);
    for(int i = 0; i < Xsize - 1; i++){
        D.at(table.at(i)) += X.at(i+1) - X.at(i);
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