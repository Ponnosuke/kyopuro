#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    vector<vector<int>> field(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        for(int j = 0; j < N; j++){
            if(S.at(j) == '#'){
                field.at(i).at(j) = -1;
            }
        }
    }

    field.at(0).at(0) = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(field.at(i).at(j) == -1){
                continue;
            }

            if(i-1 >= 0){
                if(field.at(i-1).at(j) != -1){
                    field.at(i).at(j) += field.at(i-1).at(j);
                }
            }
            if(j-1 >= 0){
                if(field.at(i).at(j-1) != -1){
                    field.at(i).at(j) += field.at(i).at(j-1);
                }
            }
        }
    }

    cout << field.at(N-1).at(N-1) << endl;
}