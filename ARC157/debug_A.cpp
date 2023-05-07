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

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const int LOOP_CNT = 1000;
const int N = 1000;

int main() {
    for(int rep = 0; rep < LOOP_CNT; rep++){
        string S = "";
        for(int i = 0; i < N; i++){
            int now = myRnd64(1, 2);
            if(now == 1){
                S += 'X';
            }
            else{
                S += 'Y';
            }
        }

        int A = 0, B = 0, C = 0, D = 0;
        for(int i = 0; i < N-1; i++){
            char first = S.at(i), second = S.at(i+1);
            if(first == 'X' && second == 'X'){
                A++;
            }
            else if(first == 'X' && second == 'Y'){
                B++;
            }
            else if(first == 'Y' && second == 'X'){
                C++;
            }
            else{
                D++;
            }
        }

        if(abs(B-C) > 1){
            cout << "Got it" << endl;
            debugV(B);
            debugVL(C);

            exit(0);
        }

        // cout << S << endl;
    }

    cout << "finish" << endl;
}