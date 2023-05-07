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
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++)  cin >> A.at(i);
    for(int i = 0; i < N; i++)  cin >> B.at(i);

    vector<vector<int>> AB(2, vector<int>(N));  // [0] := A, [1] := B
    for(int i = 0; i < N; i++){
        AB.at(0).at(i) = A.at(i);
        AB.at(1).at(i) = B.at(i);
    }

    vector<vector<bool>> dp(2, vector<bool>(N, false));
    dp.at(0).at(0) = true;
    dp.at(1).at(0) = true;
    for(int i = 0; i < N-1; i++){
        for(int from = 0; from < 2; from++){

            if(dp.at(from).at(i)){
                for(int to = 0; to < 2; to++){
                    if(abs(AB.at(to).at(i+1) - AB.at(from).at(i)) <= K){
                        dp.at(to).at(i+1) = true;
                    }
                }
            }
        }
    }

    if(dp.at(0).at(N-1) || dp.at(1).at(N-1)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}