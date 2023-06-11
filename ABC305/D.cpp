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
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    i64 Q;
    cin >> Q;
    vector<i64> l(Q), r(Q);
    for(int i = 0; i < Q; i++){
        cin >> l.at(i) >> r.at(i);
    }

    vector<i64> S(N+1, 0);
    for(int i = 1; i <= N; i++){
        if(i % 2 == 0){
            S.at(i) += S.at(i-1) + (A.at(i) - A.at(i-1));
        }
        else{
            S.at(i) += S.at(i-1);
        }
    }

    // debug
    // for(int i = 0; i < N+1; i++){
    //     debugVL(i);
    //     debugVL(S.at(i));
    // }
    // debugWL();

    for(int query = 0; query < Q; query++){
        i64 now_l = l.at(query), now_r = r.at(query);

        i64 l_idx = distance(A.begin(), lower_bound(A.begin(), A.end(), now_l));
        i64 r_idx = distance(A.begin(), lower_bound(A.begin(), A.end(), now_r));
        i64 lRet = -1, rRet = -1;

        if(l_idx == 0){
            lRet = 0;
        }
        else if(l_idx % 2 == 0){
            lRet = S.at(l_idx - 1) - S.at(0);
            lRet += now_l - A.at(l_idx - 1);
        }
        else{
            lRet = S.at(l_idx) - S.at(0);
        }

        if(r_idx == 0){
            rRet = 0;
        }
        else if(r_idx % 2 == 0){
            rRet = S.at(r_idx - 1) - S.at(0);
            rRet += now_r - A.at(r_idx - 1);
        }
        else{
            rRet = S.at(r_idx) - S.at(0);
        }

        debugV(l_idx);
        debugVL(r_idx);
        debugV(rRet);
        debugVL(lRet);

        cout << rRet - lRet << '\n';

        // if(l_idx == 0){
        //     if(r_idx == 0){
        //         cout << 0 << '\n';
        //     }
        //     else if(r_idx % 2 == 0){
        //         i64 ret = S.at(r_idx - 1) - S.at(l_idx);
        //         ret += (now_r - A.at(r_idx - 1));
        //         cout << ret << '\n';
        //     }
        //     else{
        //         i64 ret = S.at(r_idx) - S.at(l_idx);
        //         cout << ret << '\n';
        //     }
        // }
        // else if(){

        // }
    }

}