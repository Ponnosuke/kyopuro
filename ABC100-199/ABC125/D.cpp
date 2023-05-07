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
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    i64 ans = 0;
    if(N == 2){
        ans = max(A.at(0), A.at(1));
    }
    else if(N == 3){
        i64 g1 = gcd(A.at(0), A.at(1));
        i64 g2 = gcd(A.at(1), A.at(2));
        i64 g3 = gcd(A.at(0), A.at(2));

        ans = max(g1, max(g2, g3));
    }
    else{
        i64 g1 = gcd(A.at(0), A.at(1));
        i64 g2 = gcd(A.at(2), A.at(3));

        debugV(g1);
        debugVL(g2);

        vector<i64> divs;
        set<i64> divSet;
        debugWL(g1);
        for(i64 i = 1; i*i <= g1; i++){
            if(g1 % i != 0){
                continue;
            }

            if(divSet.count(i)){
                // do nothing
            }
            else{
                debugVL(i);
                divSet.insert(i);
                divs.push_back(i);
            }
            if(divSet.count(g1/i)){
                // do nothing
            }
            else{
                if(i != g1/i){
                    debugVL(g1/i);
                    divSet.insert(g1/i);
                    divs.push_back(g1/i);
                }
            }
        }
        debugWL(g2);
        for(i64 i = 1; i*i <= g2; i++){
            if(g2 % i != 0){
                continue;
            }

            if(divSet.count(i)){
                // do nothing
            }
            else{
                debugVL(i);
                divSet.insert(i);
                divs.push_back(i);
            }
            if(divSet.count(g2/i)){
                // do nothing
            }
            else{
                if(i != g2/i){
                    debugVL(g2/i);
                    divSet.insert(g2/i);
                    divs.push_back(g2/i);
                }
            }
        }

        sort(divs.begin(), divs.end(), greater<i64>());
        // debug
        debugWL(divs);
        for(int i = 0; i < divs.size(); i++){
            debug(divs.at(i));
        }
        debugWL();

        for(i64 x : divs){
            i64 cnt = 0;
            for(int i = 0; i < N; i++){
                if(A.at(i) % x != 0){
                    cnt++;
                    if(cnt > 1){
                        break;
                    }
                }
            }
            if(cnt <= 1){
                ans = x;
                break;
            }
        }
    }

    cout << ans << '\n';
}