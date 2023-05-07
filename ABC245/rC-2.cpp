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
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++)  cin >> A.at(i);
    for(int i = 0; i < N; i++)  cin >> B.at(i);

    vector<vector<int>> AB(2, vector<int>(N));  // [0] := A, [1] := B
    for(int i = 0; i < N; i++){
        AB.at(0).at(i) = A.at(i);
        AB.at(1).at(i) = B.at(i);
    }

    vector<bool> nxt(2, false), now(2, true);
    for(int i = 0; i < N-1; i++){
        for(int from = 0; from < 2; from++){
            if(now.at(from)){
                for(int to = 0; to < 2; to++){
                    if(abs(AB.at(to).at(i+1) - AB.at(from).at(i)) <= K){
                        nxt.at(to) = true;
                    }
                }
            }
        }

        now.at(0) = nxt.at(0);
        now.at(1) = nxt.at(1);
        nxt.at(0) = false;
        nxt.at(1) = false;
    }

    if(now.at(0) || now.at(1)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}