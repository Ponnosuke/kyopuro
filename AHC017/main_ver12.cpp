/*
    ver12

    xorshift で乱数生成
    一つ辺を選んで工事を移すときに影響のあるところだけを調べ、向上していた場合更新

    ver11 よりループを抜ける判定を細かくして、 LIMIT_TIME を大きくした
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


// まだデバッグしていないから正しいかわからない
/*
    変更があった k 日目の d_k について、
    前の d_k (prev_d_k) と 後の d_k (next_d_k) の差を調べる関数
    返り値が正だと変更後不満度増加、負だと減少
*/
i64 get_sum_d_diff(i64 N, vector<vector<i64>> &prev_d_k, vector<vector<i64>> &next_d_k){
    i64 sum = 0;
    for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
        sum += (next_d_k.at(i).at(j) - prev_d_k.at(i).at(j));
    }
    }

    return sum;
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
const i64 INF9 = POW9;

/*
    G(隣接リスト) に両方向の辺を入れるの忘れないように
    G  v1 -> v2
*/
vector<vector<i64>> get_dk(int N, int M, vector<vector<Edge>> &G){
    vector<vector<i64>> dk(N, vector<i64>(N, INF9));
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


/*
    "xor128()" is from shindannin's code.
    https://atcoder.jp/contests/intro-heuristics/submissions/15905939 
*/
uint32_t xor128() 
{
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;
 
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

uint32_t xRnd(uint32_t L, uint32_t R){
    uint32_t ret = L + (xor128() % (R - L + 1));
    return ret;
}

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

void ansOutput(vector<int> &r, int M){
    for(int i = 0; i < M; i++){
        cout << r.at(i);
        if(i < M-1){
            cout << " ";
        }
    }
    cout << '\n';

    return;
}

const double LIMIT_TIME = 5800.0;

int main() {
    Timer sw = Timer();

    int N, M, D, K;
    cin >> N >> M >> D >> K;
    vector<int> u(M, 0), v(M, 0);
    vector<i64> w(M, 0);
    for(int i = 0; i < M; i++){
        cin >> u.at(i) >> v.at(i) >> w.at(i);
        u.at(i)--;
        v.at(i)--;
    }
    vector<int> x(N, 0), y(N, 0);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i);
    }

    vector<int> r(M, 1);
    vector<int> dayCnt(D, 0);  // 0-indexed
    for(int i = 0; i < M; i++){
        int day = 1;
        do{
            day = xRnd(1, D);
        }while(dayCnt[day-1] >= K);

        dayCnt[day-1]++;
        r.at(i) = day;
    }

    vector<set<int>> kouji(D+1);  // kouji[d] := d(1-indexed) 日に工事をする辺の index (0-indexed) の set
    for(int i = 0; i < M; i++){
        kouji.at(r.at(i)).insert(i);
    }

    bool stop = false;
    // i64 debugCnt = 0;
    while(!stop){
        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        // debugCnt++;

        int target_edge_idx = xRnd(0, M-1);
        int prev_day = r.at(target_edge_idx);
        int next_day = xRnd(1, D);
        while(prev_day == next_day || dayCnt.at(next_day - 1) + 1 > K){
            next_day = xRnd(1, D);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        vector<vector<Edge>> prev_day_prev_G(N), prev_day_next_G(N);
        vector<vector<Edge>> next_day_prev_G(N), next_day_next_G(N);
        vector<vector<i64>> prev_day_prev_d, prev_day_next_d;
        vector<vector<i64>> next_day_prev_d, next_day_next_d;

        for(int i = 0; i < M; i++){
            if(kouji.at(prev_day).count(i)){
                continue;
            }

            int tu = u.at(i), tv = v.at(i);
            i64 tw = w.at(i);
            prev_day_prev_G.at(tu).emplace_back(Edge(tu, tv, tw, i));
            prev_day_prev_G.at(tv).emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        prev_day_prev_d = get_dk(N, M, prev_day_prev_G);

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < M; i++){
            if(kouji.at(next_day).count(i)){
                continue;
            }

            int tu = u.at(i), tv = v.at(i);
            i64 tw = w.at(i);
            next_day_prev_G.at(tu).emplace_back(Edge(tu, tv, tw, i));
            next_day_prev_G.at(tv).emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        next_day_prev_d = get_dk(N, M, next_day_prev_G);

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        kouji.at(prev_day).erase(target_edge_idx);
        kouji.at(next_day).insert(target_edge_idx);

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < M; i++){
            if(kouji.at(prev_day).count(i)){
                continue;
            }

            int tu = u.at(i), tv = v.at(i);
            i64 tw = w.at(i);
            prev_day_next_G.at(tu).emplace_back(Edge(tu, tv, tw, i));
            prev_day_next_G.at(tv).emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        prev_day_next_d = get_dk(N, M, prev_day_next_G);

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < M; i++){
            if(kouji.at(next_day).count(i)){
                continue;
            }

            int tu = u.at(i), tv = v.at(i);
            i64 tw = w.at(i);
            next_day_next_G.at(tu).emplace_back(Edge(tu, tv, tw, i));
            next_day_next_G.at(tv).emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        next_day_next_d = get_dk(N, M, next_day_next_G);

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        i64 judge_value = get_sum_d_diff(N, prev_day_prev_d, prev_day_next_d) + get_sum_d_diff(N, next_day_prev_d, next_day_next_d);

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }
        
        // もし工事する日を移す場合、dayCnt を更新するのを忘れないように
        // 移さない場合、kouji を戻すのを忘れないように
        if(judge_value <= 0){
            r.at(target_edge_idx) = next_day;
            dayCnt.at(prev_day - 1)--;
            dayCnt.at(next_day - 1)++;
        }
        else{
            kouji.at(next_day).erase(target_edge_idx);
            kouji.at(prev_day).insert(target_edge_idx);
        }

        // if(sw.GetTimeMS() > LIMIT_TIME){
        //     stop = true;
        //     break;
        // }
    }

    ansOutput(r, M);

    debugVL(sw.GetTimeMS());
    // debugVL(debugCnt);

    return 0;
}