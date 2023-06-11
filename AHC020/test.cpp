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
    int input_M;
    cin >> input_M;
    vector<int> input_w(input_M);
    for(int i = 0; i < input_M; i++){
        input_w.at(i) = input_M - i;
    }
    vector<pair<i64, i64>> edge_weight; // weight, edge's index
    for(int i = 0; i < input_M; i++){
        edge_weight.emplace_back(input_w.at(i), i);
    }
    sort(edge_weight.begin(), edge_weight.end());

    for(int i = 0; i < input_M; i++){
        debugV(edge_weight.at(i).first);
        debugVL(edge_weight.at(i).second);
    }
}