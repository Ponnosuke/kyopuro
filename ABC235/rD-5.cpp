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

const i64 INF = (1LL << 60);
const i64 MX = 1000000;

int main() {
    i64 a, N;
    cin >> a >> N;

    vector<i64> dist(MX, INF);
    dist.at(1) = 0;
    queue<i64> Q;
    Q.push(1);
    while(!Q.empty()){
        i64 v = Q.front();
        Q.pop();

        if(a*v < MX){
            if(dist.at(a*v) == INF){
                Q.push(a*v);
                dist.at(a*v) = dist.at(v) + 1;
            }
        }

        if((v >= 10) && (v % 10 != 0)){
            i64 nv = (v / 10);
            i64 add = 1;
            while(add <= nv){
                add *= 10;
            }
            nv += (add * (v % 10));

            if(nv < MX){
                if(dist.at(nv) == INF){
                    Q.push(nv);
                    dist.at(nv) = dist.at(v) + 1;
                }
            }
        }
    }

    if(dist.at(N) == INF){
        cout << -1 << endl;
    }
    else{
        cout << dist.at(N) << endl;
    }

    return 0;
}