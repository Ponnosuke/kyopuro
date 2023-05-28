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
    vector<int> P(N, -1);
    for(int i = 1; i <= N-1; i++){
        cin >> P.at(i);
    }

    vector<int> dig(N, 0);
    for(int i = 1; i <= N-1; i++){
        dig.at(i)++;
        dig.at(P.at(i))++;
        
    }

    int cnt = 0;
    for(int i = 1; i < N; i++){
        if(dig.at(i) == 1){
            cnt++;
        }
    }



    cout << cnt << endl;

    return 0;
}