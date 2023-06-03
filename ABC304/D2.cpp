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
    for(int i = 0; i < N; i++){
        cin >> p.at(i) >> q.at(i);
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

    map<pair<i64, i64>, i64> cnt;
    for(int i = 0; i < N; i++){
        i64 xIdx = distance(a.begin(), lower_bound(a.begin(), a.end(), p.at(i)));
        i64 yIdx = distance(b.begin(), lower_bound(b.begin(), b.end(), q.at(i)));

        cnt[make_pair(xIdx, yIdx)]++;
    }

    i64 cntMin = N+1, cntMax = -1;
    for(auto [vp, cq] : cnt){
        cntMin = min(cntMin, cq);
        cntMax = max(cntMax, cq);
    }


    i64 sumCnt = (A+1)*(B+1);
    if(sumCnt > cnt.size()){
        cntMin = 0;
    }


    cout << cntMin << " " << cntMax << '\n';

    return 0;
}