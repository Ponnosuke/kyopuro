#include <bits/stdc++.h>
#include <atcoder/dsu>

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
    i64 W, H;
    cin >> W >> H;
    i64 N;
    cin >> N;
    vector<i64> p(N), q(N);
    vector<pair<i64, i64>> pq(N);
    for(int i = 0; i < N; i++){
        cin >> p.at(i) >> q.at(i);
        pq.at(i) = make_pair(p.at(i), q.at(i));
    }
    i64 A;
    cin >> A;
    vector<i64> a(A);
    for(int i = 0; i < A; i++){
        cin >> a.at(i);
    }
    i64 B;
    cin >> B;
    vector<i64> b(B);
    for(int i = 0; i < B; i++){
        cin >> b.at(i);
    }

    atcoder::dsu uf(N);
    set<i64> stX, stY;
    for(int i = 0; i < A; i++){
        stX.insert(a.at(i));
    }
    for(int i = 0; i < B; i++){
        stY.insert(b.at(i));
    }

    sort(pq.begin(), pq.end());

    // debug
    // debugWL(pq);
    // for(int i = 0; i < N; i++){
    //     debugV(pq.at(i).first);
    //     debugVL(pq.at(i).second);
    // }
    // debugWL();

    for(int i = 0; i < N-1; i++){

        debugVL(i);

        pair<i64, i64> cake1 = pq.at(i), cake2 = pq.at(i+1);
        i64 minP = min(cake1.first, cake2.first), minQ = min(cake1.second, cake2.second);
        i64 maxP = max(cake1.first, cake2.first), maxQ = max(cake1.second, cake2.second);

        debugV(cake1.first);
        debugVL(cake1.second);
        debugV(cake2.first);
        debugVL(cake2.second);

        bool OK1 = true, OK2 = true;
        auto itrX = stX.lower_bound(minP);

        i64 judgeX = *itrX;
        if(itrX == stX.end()){
            // do nothing
        }
        else if(judgeX <= maxP){
            OK1 = false;
        }
        auto itrY = stY.lower_bound(minQ);
        i64 judgeY = *itrY;
        if(itrY == stY.end()){
            // do nothing
        }
        else if(judgeY <= maxQ){
            OK2 = false;
        }

        debugV(judgeX);
        debugVL(judgeY);

        if(OK1 && OK2){

            debugWL(merge);

            uf.merge(i, i+1);
        }
    }

    i64 cntMin = N+1, cntMax = -1;
    for(int i = 0; i < N; i++){
        cntMin = min(cntMin, (i64)uf.size(i));
        cntMax = max(cntMax, (i64)uf.size(i));
    }

    if(cntMin == 1){
        i64 sumCnt = (A+1)*(B+1);
        if(sumCnt > N){
            cntMin = 0;
        }
    }

    cout << cntMin << " " << cntMax << '\n';

    return 0;
}