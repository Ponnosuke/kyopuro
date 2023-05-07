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
    i64 N, Q;
    cin >> N >> Q;

    set<i64> gone;
    queue<i64> notCalled;
    priority_queue<i64, vector<i64>, greater<i64>> called;
    for(i64 i = 1; i <= N; i++){
        // notCalled.emplace(i);
        notCalled.push(i);
    }

    debugP();

    for(i64 qi = 0; qi < Q; qi++){

        debugVL(qi);

        int type;
        cin >> type;

        debugVL(type);

        if(type == 1){
            i64 num = notCalled.front();
            notCalled.pop(); 
            called.push(num);  
        }
        if(type == 2){
            i64 x;
            cin >> x;
            gone.insert(x);
        }
        if(type == 3){
            i64 numTop = called.top();
            while(gone.count(numTop)){
                debugP();
                called.pop();
                numTop = called.top();
            }
            cout << numTop << '\n';
        }
    }
}