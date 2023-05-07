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

void dfs(i64 N, i64 now, i64 K, vector<i64> &A, vector<i64> &B, i64 index, bool &OK){
    if(index == N){
        OK = true;
        return;
    }

    if(abs(now - A.at(index)) <= K){
        dfs(N, A.at(index), K, A, B, index + 1, OK);
    }
    if(abs(now - B.at(index)) <= K){
        dfs(N, B.at(index), K, A, B, index + 1, OK);
    }

    return;
}

bool solver1(i64 N, i64 K, vector<i64> &A, vector<i64> &B){
    bool OK = false;
    dfs(N, A.at(0), K, A, B, 1, OK);
    dfs(N, B.at(0), K, A, B, 1, OK);

    return OK;
}

bool solver2(i64 N, i64 K, vector<i64> &A, vector<i64> &B){
    bool OK = false;
    bool OK_A = true, OK_B = true;
    for(i64 i = 0; i < N-1; i++){
        bool nxOK_A = false, nxOK_B = false;
        if(OK_A){
            if(abs(A.at(i+1) - A.at(i)) <= K){
                nxOK_A = true;
            }
            if(abs(B.at(i+1) - A.at(i)) <= K){
                nxOK_B = true;
            }
        }
        if(OK_B){
            if(abs(A.at(i+1) - B.at(i)) <= K){
                nxOK_A = true;
            }
            if(abs(B.at(i+1) - B.at(i)) <= K){
                nxOK_B = true;
            }
        }

        if(i+1 == N-1){
            if(nxOK_A || nxOK_B){
                OK = true;
                break;
            }
        }

        OK_A = nxOK_A;
        OK_B = nxOK_B;
    }

    return OK;
}

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const i64 LOOP_CNT = 100;
const i64 POW9 = 1000000000;

int main() {
    debugWL(start);
    for(i64 i = 0; i < LOOP_CNT; i++){

        debugVL(i);

        i64 N = myRnd64(1, 25);
        i64 K = myRnd64(0, POW9);
        vector<i64> A(N), B(N);
        for(int j = 0; j < N; j++){
            A.at(j) = myRnd64(1, POW9);
            B.at(j) = myRnd64(1, POW9);
        }

        bool sol1 = solver1(N, K, A, B);
        bool sol2 = solver2(N, K, A, B);

        if(sol1 != sol2){
            debugWL(Wrong!);

            debugV(N);
            debugVL(K);
            debugWL(A);
            for(auto ele : A){
                debug(ele);
            }
            debugWL();
            debugWL(B);
            for(auto ele : B){
                debug(ele);
            }
            debugWL();

            debugWL(sol1:);
            if(sol1){
                debugWL(Yes);
            }
            else{
                debugWL(No);
            }
            debugWL(sol2:);
            if(sol2){
                debugWL(Yes);
            }
            else{
                debugWL(No);
            }

            exit(1);
        }
    }
    debugWL(finish);
}