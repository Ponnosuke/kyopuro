/*
    ワーシャルフロイド法で実装してみる
    遅すぎてダメそう。没。
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

class Timer{
    private:
        std::chrono::system_clock::time_point m_start;
    public:
        Timer() :m_start(std::chrono::system_clock::now()) {
            std::cerr << fixed << setprecision(18);
        }
    public:
        void Reset(){
            m_start = std::chrono::system_clock::now();
        }
        double GetTimeMS(){
            auto end = std::chrono::system_clock::now();
            return (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start).count();
        }
        double GetTimeSec(){
            auto end = std::chrono::system_clock::now();
            return (double)std::chrono::duration_cast<std::chrono::seconds>(end - m_start).count();
        }
};

/*
    v1 := 頂点1
    v2 := 頂点2
    w := v1 v2 間にある辺の長さ
    index := v1 v2 間の辺の番号
*/
struct Edge {
    int v1;
    int v2;
    i64 w;
    int index;

    Edge(int _v1, int _v2, i64 _w, int _index) : v1(_v1), v2(_v2), w(_w), index(_index) {
    }
    Edge(){
    }

    void Set(int _v1, int _v2, i64 _w, int _index){
        v1 = _v1;
        v2 = _v2;
        w = _w;
        index = _index;

        return;
    }
};

/*
    k 日目の不満度を返す

    N := 頂点数
    d_k[i][j] := k 日目の 頂点i から 頂点j への最短距離
    d[i][j] := どこも工事をしていない時の i から j への最短距離
*/
double getFk(i64 N, vector<vector<i64>> &d_k, vector<vector<i64>> &d){
    i64 sum = 0;

    // 愚直計算
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }

            sum += (d_k.at(i).at(j) - d.at(i).at(j));
        }
    }
    */

   // こっちで大丈夫っぽい？
   for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
        sum += (d_k.at(i).at(j) - d.at(i).at(j));
    }
   }
   sum *= 2;

   double dSum = sum, dN = N;
   dSum /= (dN * (dN-1));

   return dSum;
}


/*
    工事全体に対する不満度を返す

    D := 日数
    f_k[k] := k 日目の不満度 (k は 0-indexed)
*/
i64 getFumando(int D, vector<double> &f_k){
    const i64 POW3 = 1000;
    double sum = 0;
    for(int i = 0; i < D; i++){
        sum += f_k.at(i);
    }

    double dD = D, dPow = POW3;
    i64 ret;
    ret = round(dPow * (sum / D));

    return ret;
}

const i64 POW9 = 1000000000;
const i64 INF = POW9;

/*
    G(隣接リスト) に両方向の辺を入れるの忘れないように
    G  v1 -> v2
*/
vector<vector<i64>> get_dk(int N, int M, vector<vector<Edge>> &G){
    vector<vector<i64>> dk(N, vector<i64>(N, INF));
    priority_queue< pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>> > pq;

    for(int start = 0; start < N; start++){
        dk.at(start).at(start) = 0;
        vector<bool> done(N, false);
        pq.emplace(make_pair(dk.at(start).at(start), start));
        while(!pq.empty()){
            auto [d, v] = pq.top();
            pq.pop();

            if(done.at(v)){
                continue;
            }

            for(auto e : G.at(v)){
                int v1 = e.v1, v2 = e.v2;
                i64 w = e.w;

                // v1 -> v2
                if(dk.at(start).at(v2) > dk.at(start).at(v1) + w){
                    dk.at(start).at(v2) = dk.at(start).at(v1) + w;
                    pq.emplace(make_pair(dk.at(start).at(v2), v2));
                }
            }

            done.at(v) = true;
        }
    }

    return dk;
}


void get_dk2(int N, vector<vector<i64>> &d_k){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){

                if(d_k.at(i).at(k) == INF || d_k.at(k).at(j) == INF){
                    continue;
                }

                d_k.at(i).at(j) = min(d_k.at(i).at(j), d_k.at(i).at(k) + d_k.at(k).at(j));
            }
        }
    }

    return;
}


int main() {
    Timer sw = Timer();

    debugWL(start);

    int N, M, D, K;
    cin >> N >> M >> D >> K;
    vector<int> u(M, 0), v(M, 0);
    vector<i64> w(M, 0);
    vector<vector<i64>> ini_d(N, vector<i64>(N, INF));
    for(int i = 0; i < M; i++){
        cin >> u.at(i) >> v.at(i) >> w.at(i);
        u.at(i)--;
        v.at(i)--;

        ini_d.at(u.at(i)).at(v.at(i)) = w.at(i);
        ini_d.at(v.at(i)).at(u.at(i)) = w.at(i);
    }
    vector<int> x(N, 0), y(N, 0);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i);
    }
    for(int i = 0; i < N; i++){
        ini_d.at(i).at(i) = 0;
    }

    debugWL(pointA);


    vector<int> r(M, 0);
    for(int i = 0; i < M; i++){
        cin >> r.at(i);
    }

    debugWL(pointA2);

    vector<vector<int>> kouji(D+1);  // kouji[d] := d(1-indexed) 日に工事をする辺の index (0-indexed) の set
    for(int i = 0; i < M; i++){
        kouji.at(r.at(i)).push_back(i);        
    }

    debugWL(pointA3);

    // 工事無し
    /*
    vector<vector<Edge>> original_G(N); // u -> v
    for(int i = 0; i < M; i++){
        original_G.at(u.at(i)).push_back(Edge(u.at(i), v.at(i), w.at(i), i));
        original_G.at(v.at(i)).push_back(Edge(v.at(i), u.at(i), w.at(i), i));
    }
    vector<vector<i64>> original_d = get_dk(N, M, original_G);  // original_d[i][j] := i と j の最短距離
    */
   vector<vector<i64>> original_d = ini_d;
    get_dk2(N, original_d);

    debugWL(pointB);
    vector<double> f_k(D, 0);
    for(int day = 1; day <= D; day++){
        vector<vector<i64>> d_k = ini_d;
        for(int edge_index : kouji.at(day)){
            int tu = u.at(edge_index), tv = v.at(edge_index);
            d_k.at(tu).at(tv) = INF;
            d_k.at(tv).at(tu) = INF;
        }

        get_dk2(N, d_k);

        f_k.at(day - 1) = getFk(N, d_k, original_d);
    }

    debugWL(pointC);

    double time = sw.GetTimeMS();
    cerr << "Fumando: ";
    cerr << getFumando(D, f_k) << '\n';
    cerr << "time = " << time << '\n';

    debugWL(Finish);
}