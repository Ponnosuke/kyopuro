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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    int maxR = -1, minL = INF;
    for(int i = 0; i < N; i++){
        cin >> L.at(i) >> R.at(i);
        maxR = max(maxR, R.at(i));
        minL = min(minL, L.at(i));
    }

    vector<int> table(maxR + 1, 0);
    for(int i = 0; i < N; i++){
        int Li = L.at(i), Ri = R.at(i);
        table.at(Li)++;
        table.at(Ri)--;
    }
    for(int i = minL; i <= maxR; i++){
        table.at(i) += table.at(i-1);
        if(table.at(i-1) == 0 && table.at(i) > 0){
            cout << i << " ";
        }

        if(table.at(i-1) > 0 && table.at(i) == 0){
            cout << i << '\n';
        } 
    }
}