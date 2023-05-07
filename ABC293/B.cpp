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
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        A.at(i)--;
    }

    vector<bool> flag(N, false);
    for(int i = 0; i < N; i++){
        if(!flag.at(i)){
            flag.at(A.at(i)) = true;
        }
    }

    vector<int> X;
    for(int i = 0; i < N; i++){
        if(!flag.at(i)){
            X.push_back(i);
        }
    }

    
    cout << (int)X.size() << '\n';
    for(int i = 0; i < X.size(); i++){
        cout << X.at(i) + 1;

        if(i < (int)X.size()-1){
            cout << " ";
        }
    }
    cout << '\n';
}