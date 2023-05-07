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
    }

    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(A.at(i) % 2 == 0){
            ans.push_back(A.at(i));
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i);

        if(i < (int)ans.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}