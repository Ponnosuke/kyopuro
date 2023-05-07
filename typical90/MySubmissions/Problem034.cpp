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

// bool isNG()

int main() {
    int N;
    int K;
    cin >> N >> K;
    vector<int> a(N, 0);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    unordered_map<int, int> ump;
    unordered_set<int> US;
    queue<int> Q;
    int ans = -1, cnt = 0;;
    for(int ele : a){
        Q.push(ele);
        US.insert(ele);
        ump[ele]++;
        cnt++;

        debugV(ele);
        debugVL(US.size());

        while(US.size() > K && !Q.empty()){
            int v = Q.front();
            Q.pop();
            cnt--;
            ump.at(v)--;
            if(ump.at(v) == 0){
                US.erase(v);
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}