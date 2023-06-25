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
    deque<string> dq;
    dq.push_back("");
    for(int i = 0; i < N; i++){
        debugVL(i);
        debugVL(S.at(i));
        if(S.at(i) == '('){

            debugP();

            dq.push_back("");
            dq.back() += S.at(i);
        }
        else if(S.at(i) == ')'){

            debugP();

            if(dq.size() > 1){
                dq.pop_back();
            }
            else{
                dq.back() += S.at(i);
            }
        }
        else{

            debugP();

            dq.back() += S.at(i);
        }

        debugVL(dq.back());
        debugWL();
    }

    string ans = "";
    while(!dq.empty()){
        string str = dq.front();
        dq.pop_front();
        ans += str;
    }

    cout << ans << '\n';
}