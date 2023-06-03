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
    vector<string> S(N);
    vector<int> A(N);
    int minA = INF, minIdx = -1;
    for(int i = 0; i < N; i++){
        string iS;
        int iA;
        cin >> iS >> iA;

        S.at(i) = iS;
        A.at(i) = iA;

        if(minA > iA){
            minA = iA;
            minIdx = i;
        }
    }

    for(int rep = 0; rep < N; rep++){
        cout << S.at((minIdx + rep) % N) << '\n';
    }
}