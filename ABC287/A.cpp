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
    vector<string> S(N);
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
        if(S.at(i) == "For"){
            cnt++;
        }
    }

    if(cnt >= ((N/2) + 1)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}