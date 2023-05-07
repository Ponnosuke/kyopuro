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

    queue<int> L;
    stack<int> R;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'L'){
            R.push(i);
        }
        else{
            L.push(i);
        }
    }
    L.push(N);

    while(!L.empty()){
        cout << L.front() << " ";
        L.pop();
    }
    while(!R.empty()){
        cout << R.top() << " ";
        R.pop();
    }
    cout << '\n';

    return 0;
}