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
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    stack<pair<int, int>> sta;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            cnt++;
            sta.emplace(a.at(0), 1);
        }
        else if((!sta.empty()) && (sta.top().first == a.at(i))){
            sta.top().second++;
            cnt++;
            if(sta.top().second % a.at(i) == 0){
                sta.pop();
                cnt -= a.at(i);
            }
        }
        else{
            cnt++;
            sta.emplace(a.at(i), 1);

        }

        cout << cnt << '\n';
    }
}