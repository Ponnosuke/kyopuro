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
    vector<int> P(N, 0), scores(N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            int score;
            cin >> score;
            P.at(i) += score;
        }
        scores.at(i) = P.at(i);
    }

    sort(scores.begin(), scores.end());
    vector<bool> isOK(N, false);
    for(int i = 0; i < N; i++){
        int now = P.at(i) + 300;
        int rank = distance(upper_bound(scores.begin(), scores.end(), now), scores.end());
        if(rank < K){
            isOK.at(i) = true;
        }
    }

    for(int i = 0; i < N; i++){
        if(isOK.at(i)){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}