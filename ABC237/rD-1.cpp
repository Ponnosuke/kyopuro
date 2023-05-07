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

    deque<int> A;
    A.push_back(N);
    for(int i = N-1; i >= 0; i--){
        if(S.at(i) == 'L'){
            A.push_back(i);
        }
        else{
            A.push_front(i);
        }
    }

    for(int i = 0; i < N+1; i++){
        cout << A.at(i);

        if(i < N){
            cout << " ";
        }
    }
    cout << '\n';
}