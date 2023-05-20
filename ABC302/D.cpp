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
    i64 N, M, D;
    cin >> N >> M >> D;
    vector<i64> A(N), B(M);
    for(int i = 0; i < N; i++)  cin >> A.at(i);
    for(int i = 0; i < M; i++)  cin >> B.at(i);

    sort(A.begin(), A.end(), greater<i64>());
    sort(B.begin(), B.end(), greater<i64>());

    queue<i64> qA, qB;
    for(int i = 0; i < N; i++){
        qA.push(A.at(i));
    }
    for(int j = 0; j < M; j++){
        qB.push(B.at(j));
    }

    // int idx_A = N-1, idx_B = M-1;
    i64 ans = -1;
    while(!qA.empty() || !qB.empty()){
        if(abs(qA.front() - qB.front()) <= D){
            ans = max(ans, qA.front() + qB.front());
        }

        if(qA.empty()){
            qB.pop();
        }
        else if(qB.empty()){
            qA.pop();
        }
        else{
            if(qA.front() >= qB.front()){
                qA.pop();
            }
            else{
                qB.pop();
            }
        }
    }

    cout << ans << '\n';

    return 0;
}