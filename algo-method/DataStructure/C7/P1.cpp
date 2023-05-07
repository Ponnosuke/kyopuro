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
    stack<char> sta;
    sta.push('A');
    sta.push('B');
    sta.push('C');
    sta.pop();
    sta.push('X');
    sta.push('Y');
    sta.push('Z');
    sta.pop();

    vector<char> ans;
    while(!sta.empty()){
        char ch = sta.top();
        sta.pop();
        ans.push_back(ch);
    }
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ((i < ans.size() - 1) ? ' ' : '\n');
    }

}