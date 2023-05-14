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
    string S;
    cin >> S;

    char loser;
    map<char, int> cnt;
    for(int i = 0; i < N; i++){
        char nowCh = S.at(i);

        cnt[nowCh]++;
        loser = nowCh;
    }

    if(cnt['T'] > cnt['A']){
        cout << 'T' << endl;
    }
    else if(cnt['T'] < cnt['A']){
        cout << 'A' << endl;
    }
    else{
        if(loser == 'T'){
            cout << 'A' << endl;
        }
        else{
            cout << 'T' << endl;
        }
    }

    return 0;
}