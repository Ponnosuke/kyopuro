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
    int N, A, B;
    cin >> N >> A >> B;

    bool flag = true, iniFlag = false;
    for(int i = 0; i < A*N; i++){
        flag = !iniFlag;
        if(i % A == 0){
            flag = !flag;
        }

        for(int j = 0; j < B*N; j++){
            if(j % B == 0){
                flag = !flag;
            }

            if(j == 0){
                iniFlag = flag;
            }

            if(flag){
                cout << ".";
            }
            else{
                cout << "#";
            }
        }

        cout << '\n';
    }

    return 0;
}