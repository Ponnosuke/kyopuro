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
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    debugP();

    set<i64> priceList;
    for(int mask = 0; mask < (1 << N); mask++){
        debugVL(mask);

        queue<i64> tmp;
        tmp.push(0);

        debugP();

        for(int j = 0; j < N; j++){
            if((mask >> j) & 1){
                queue<i64> tmp2;
                while(!tmp.empty()){

                    debugP();

                    i64 ele = tmp.front();
                    tmp.pop();

                    for(int ik = 1; ik <= K; ik++){
                        tmp2.push(ele + ik*A.at(j));
                    }

                    debugP();
                }
                swap(tmp, tmp2);
            }
        }

        debugP();
        
        while(!tmp.empty()){
            i64 ele = tmp.front();
            tmp.pop();
            priceList.insert(ele);
        }

        debugP();
    }

    debugP();

    debugVL(*next(priceList.begin(), K-1));
    debugVL(*next(priceList.begin(), K));
    debugVL(*next(priceList.begin(), K+1));


    cout << *next(priceList.begin(), K) << endl;
}