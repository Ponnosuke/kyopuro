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
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> isCat(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int U, V;
        cin >> U >> V;
        U--;
        V--;

        isCat.at(U).at(V) = true;
        isCat.at(V).at(U) = true;
    }

    int cnt = 0;
    for(int a = 0; a < N; a++){
        for(int b = a+1; b < N; b++){
            for(int c = b+1; c < N; c++){
                bool OK1 = isCat.at(a).at(b);
                bool OK2 = isCat.at(b).at(c);
                bool OK3 = isCat.at(c).at(a);
                if(OK1 && OK2 && OK3){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}