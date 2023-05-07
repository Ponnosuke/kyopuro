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

// LULURU

int main() {
    i64 N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    deque<char> dq;
    for(int i = 0; i < N; i++){
        if(!dq.empty()){
            char pre = dq.back();
            char now = S.at(i);
            if(now == 'U'){
                if(pre == 'R' || pre == 'L'){
                    dq.pop_back();
                }
                else{
                    dq.push_back(now);
                }
            }
            else{
                dq.push_back(now);
            }
        }
        else{
            dq.push_back(S.at(i));
        }

    }

    while(!dq.empty()){
        char q = dq.front();
        dq.pop_front();

        if(q == 'U'){
            X /= 2;
        }
        else if(q == 'L'){
            X *= 2;
        }
        else{  // R
            X *= 2;
            X += 1;
        }
    }

    cout << X << '\n';
}