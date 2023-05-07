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
    vector<int> P(N, 0);
    vector<int> scores(N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            int num;
            cin >> num;
            P.at(i) += num;
        }

        scores.at(i) = P.at(i);
    }

    nth_element(scores.begin(), next(scores.begin(), K-1), scores.end(), greater<int>());
    for(int i = 0; i < N; i++){
        if(P.at(i) + 300 >= scores.at(K-1)){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}