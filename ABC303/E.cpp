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
    i64 N;
    cin >> N;
    vector<i64> u(N-1), v(N-1);
    vector<i64> dig(N, 0);
    for(int i = 0; i < N-1; i++){
        i64 iu, iv;
        cin >> iu >> iv;

        u.at(i) = iu;
        v.at(i) = iv;

        iu--;
        iv--;
        dig.at(iu)++;
        dig.at(iv)++;
    }

    sort(dig.begin(), dig.end(), greater<i64>());

    i64 vCnt = N;
    vector<i64> ans;
    for(int i = 0; i < N; i++){
        ans.push_back(dig.at(i));
        vCnt -= dig.at(i) + 1;

        if(vCnt <= 0){
            break;
        }
    }

    sort(ans.begin(), ans.end());

    int ansSize = ans.size();
    for(int i = 0; i < ansSize; i++){
        cout << ans.at(i);

        if(i < ansSize - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}