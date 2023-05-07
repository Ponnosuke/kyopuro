/*
    ver20

    xorshift で乱数生成

    ver17から継承、次数の大きい頂点からターゲットにして、そこから全頂点への経路を求めてそれによって評価
    始点となる頂点の数を target_vertex_cnt = 100 で管理
    int route_select_value を実装して、これの値によって、辺を移すか交換するかを選ぶ
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
   for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
        sum += (d_k[i][j] - d[i][j]);
    }
   }
   sum *= 2;

   double dSum = sum, dN = N;
   dSum /= (dN * (dN-1));

   return dSum;
}


/*
    変更があった k 日目の d_k について、
    前の d_k (prev_d_k) と 後の d_k (next_d_k) の差を調べる関数
    返り値が正だと変更後不満度増加、負だと減少
*/
i64 get_sum_d_diff(i64 N, vector<vector<i64>> &prev_d_k, vector<vector<i64>> &next_d_k){
    i64 sum = 0;
    for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
        sum += (next_d_k[i][j] - prev_d_k[i][j]);
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
        sum += f_k[i];
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
        dk[start][start] = 0;
        vector<bool> done(N, false);
        pq.emplace(make_pair(dk[start][start], start));
        while(!pq.empty()){
            auto [d, v] = pq.top();
            pq.pop();

            if(done[v]){
                continue;
            }

            for(auto e : G[v]){
                int v1 = e.v1, v2 = e.v2;
                i64 w = e.w;

                // v1 -> v2
                if(dk[start][v2] > dk[start][v1] + w){
                    dk[start][v2] = dk[start][v1] + w;
                    pq.emplace(make_pair(dk[start][v2], v2));
                }
            }

            done[v] = true;
        }
    }

    return dk;
}

/*
    v_k を始点とするダイクストラ法。 v_k から各頂点への距離を返す
*/
vector<i64> get_dk_mono(int N, int M, int v_k, vector<vector<Edge>> &G){
    vector<i64> dk_mono(N, INF9);
    priority_queue< pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>> > pq;

    dk_mono[v_k] = 0;
    vector<bool> done(N, false);
    pq.emplace(make_pair(dk_mono[v_k], 0));
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(done[v]){
            continue;
        }

        for(auto e : G[v]){
            int v1 = e.v1, v2 = e.v2;
            i64 w = e.w;

            // v1 -> v2
            if(dk_mono[v2] > dk_mono[v1] + w){
                dk_mono[v2] = dk_mono[v1] + w;
                pq.emplace(make_pair(dk_mono[v2], v2));
            }
        }

        done[v] = true;
        
    }

    return dk_mono;
}

/*
    変更があった k 日目の dk_mono について、
    前の dk_mono (prev_dk_mono) と 後の dk_mono (next_dk_mono) の差を調べる関数
    返り値が正だと変更後不満度増加、負だと減少
*/
i64 get_sum_d_mono_diff(i64 N, vector<i64> &prev_dk_mono, vector<i64> &next_dk_mono){
    i64 sum = 0;
    for(int i = 0; i < N; i++){
        sum += (next_dk_mono[i] - prev_dk_mono[i]);
    }

    return sum;
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
        cout << r[i];
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
    vector<pair<int, int>> deg(N); // first := 次数、 second := 頂点番号
    for(int i = 0; i < N; i++){
        deg[i] = make_pair(0, i);
    }
    for(int i = 0; i < M; i++){
        int iu, iv, iw;
        cin >> iu >> iv >> iw;
        iu--;
        iv--;
        u[i] = iu;
        v[i] = iv;
        w[i] = iw;

        deg[iu].first++;
        deg[iv].first++;
    }
    vector<int> x(N, 0), y(N, 0);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }

    auto pGreater = [](pair<int, int> p1, pair<int, int> p2){
        return p1.first > p2.first;
    };
    sort(deg.begin(), deg.end(), pGreater);
    /*
    vector<int> sorted_vertexes(N, 0);
    for(int i = 0; i < N; i++){
        sorted_vertexes[i] = deg[i].second;
    }
    */

    /*
    int max_deg_v = 0, max_deg = -1;
    for(int i = 0; i < N; i++){
        if(max_deg < deg[i].first){
            max_deg = deg[i].first;
            max_deg_v = i;
        }
    }
    */

    vector<int> r(M, 1);
    vector<int> dayCnt(D, 0);  // 0-indexed
    for(int i = 0; i < M; i++){
        int day = 1;
        do{
            day = xRnd(1, D);
        }while(dayCnt[day-1] >= K);

        dayCnt[day-1]++;
        r[i] = day;
    }

    vector<set<int>> kouji(D+1);  // kouji[d] := d(1-indexed) 日に工事をする辺の index (0-indexed) の set
    for(int i = 0; i < M; i++){
        kouji[r[i]].insert(i);
    }

    bool stop = false;
    // i64 debugCnt = 0;
    int target_vertex_cnt = 100;
    int prev_target_edge_idx = -1;
    int route_select_value = xRnd(1, 100);
    int route_select_level = 50;
    int prev_target_edge_idx2 = -2;

    // debug
    vector<pair<double, int>> debugOut;  // 1 := change, 0 := not change

    while(!stop){
        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        // debugCnt++;
        int target_edge_idx;
        int prev_day, next_day;

        int target_edge_idx2;

        // debugVL(route_select_value);

        if(route_select_value > route_select_level){
            target_edge_idx = xRnd(0, M-1);
            while(target_edge_idx == prev_target_edge_idx){
                target_edge_idx = xRnd(0, M-1);
            }
            prev_day = r[target_edge_idx];
            next_day = xRnd(1, D);
            while(prev_day == next_day || dayCnt[next_day - 1] + 1 > K){
                next_day = xRnd(1, D);
            }

            // debugWL(routeA);
        }
        else{
            target_edge_idx = xRnd(0, M-1);
            target_edge_idx2 = xRnd(0, M-1);

            bool flag1 = ( (target_edge_idx == prev_target_edge_idx) || (target_edge_idx == prev_target_edge_idx2) );
            bool flag2 = ( (target_edge_idx2 == prev_target_edge_idx) || (target_edge_idx2 == prev_target_edge_idx2) );
            bool flag3 = ( target_edge_idx == target_edge_idx2 );
            bool flag4 = ( r[target_edge_idx] == r[target_edge_idx2] );

            while((flag1 && flag2) || flag3 || flag4){
                target_edge_idx = xRnd(0, M-1);
                target_edge_idx2 = xRnd(0, M-1);

                flag1 = ( (target_edge_idx == prev_target_edge_idx) || (target_edge_idx == prev_target_edge_idx2) );
                flag2 = ( (target_edge_idx2 == prev_target_edge_idx) || (target_edge_idx2 == prev_target_edge_idx2) );
                flag3 = (target_edge_idx == target_edge_idx2);
                flag4 = ( r[target_edge_idx] == r[target_edge_idx2] );
            }

            prev_day = r[target_edge_idx];
            next_day = r[target_edge_idx2];

            // debugWL(routeB);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        vector<vector<Edge>> prev_day_prev_G(N), prev_day_next_G(N);
        vector<vector<Edge>> next_day_prev_G(N), next_day_next_G(N);
        // vector<vector<i64>> prev_day_prev_d, prev_day_next_d;
        // vector<vector<i64>> next_day_prev_d, next_day_next_d;
        vector<vector<i64>> prev_day_prev_d_mono(target_vertex_cnt), prev_day_next_d_mono(target_vertex_cnt);
        vector<vector<i64>> next_day_prev_d_mono(target_vertex_cnt), next_day_next_d_mono(target_vertex_cnt);

        for(int i = 0; i < M; i++){
            if(kouji[prev_day].count(i)){
                continue;
            }

            int tu = u[i], tv = v[i];
            i64 tw = w[i];
            prev_day_prev_G[tu].emplace_back(Edge(tu, tv, tw, i));
            prev_day_prev_G[tv].emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < target_vertex_cnt; i++){
            prev_day_prev_d_mono[i] = get_dk_mono(N, M, deg[i].second, prev_day_prev_G);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < M; i++){
            if(kouji[next_day].count(i)){
                continue;
            }

            int tu = u[i], tv = v[i];
            i64 tw = w[i];
            next_day_prev_G[tu].emplace_back(Edge(tu, tv, tw, i));
            next_day_prev_G[tv].emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < target_vertex_cnt; i++){
            next_day_prev_d_mono[i] = get_dk_mono(N, M, deg[i].second, next_day_prev_G);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        if(route_select_value > route_select_level){
            kouji[prev_day].erase(target_edge_idx);
            kouji[next_day].insert(target_edge_idx);
        }
        else{

            // debug  後で消す
            // assert(kouji[prev_day].count(target_edge_idx));
            // assert(kouji[next_day].count(target_edge_idx2));


            kouji[prev_day].erase(target_edge_idx);
            kouji[next_day].insert(target_edge_idx);

            kouji[next_day].erase(target_edge_idx2);
            kouji[prev_day].insert(target_edge_idx2);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < M; i++){
            if(kouji[prev_day].count(i)){
                continue;
            }

            int tu = u[i], tv = v[i];
            i64 tw = w[i];
            prev_day_next_G[tu].emplace_back(Edge(tu, tv, tw, i));
            prev_day_next_G[tv].emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < target_vertex_cnt; i++){
            prev_day_next_d_mono[i] = get_dk_mono(N, M, deg[i].second, prev_day_next_G);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < M; i++){
            if(kouji[next_day].count(i)){
                continue;
            }

            int tu = u[i], tv = v[i];
            i64 tw = w[i];
            next_day_next_G[tu].emplace_back(Edge(tu, tv, tw, i));
            next_day_next_G[tv].emplace_back(Edge(tv, tu, tw, i));
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        for(int i = 0; i < target_vertex_cnt; i++){
            next_day_next_d_mono[i] = get_dk_mono(N, M, deg[i].second, next_day_next_G);
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }

        i64 judge_value = 0;
        for(int i = 0; i < target_vertex_cnt; i++){
            judge_value += ( get_sum_d_mono_diff(N, prev_day_prev_d_mono[i], prev_day_next_d_mono[i]) + get_sum_d_mono_diff(N, next_day_prev_d_mono[i], next_day_next_d_mono[i]) );
        }

        if(sw.GetTimeMS() > LIMIT_TIME){
            stop = true;
            break;
        }
        
        // もし工事する日を移す場合、dayCnt を更新するのを忘れないように
        // 移さない場合、kouji を戻すのを忘れないように
        if(judge_value <= 0){
            if(route_select_value > route_select_level){
                
                // debug
                debugOut.emplace_back(make_pair(sw.GetTimeMS(), 1));

                r[target_edge_idx] = next_day;
                dayCnt[prev_day - 1]--;
                dayCnt[next_day - 1]++;

                prev_target_edge_idx = target_edge_idx;
            }
            else{
                // debug
                debugOut.emplace_back(make_pair(sw.GetTimeMS(), 1));

                r[target_edge_idx] = next_day;
                r[target_edge_idx2] = prev_day;

                prev_target_edge_idx = target_edge_idx;
                prev_target_edge_idx2 = target_edge_idx2;
            }
        }
        else{
            if(route_select_value > route_select_level){
                // debug
                debugOut.emplace_back(make_pair(sw.GetTimeMS(), 0));

                kouji[next_day].erase(target_edge_idx);
                kouji[prev_day].insert(target_edge_idx);
            }
            else{
                // debug  後で消す
                // assert(kouji[next_day].count(target_edge_idx));
                // assert(kouji[prev_day].count(target_edge_idx2));

                // debug
                debugOut.emplace_back(make_pair(sw.GetTimeMS(), 0));


                kouji[next_day].erase(target_edge_idx);
                kouji[prev_day].insert(target_edge_idx);

                kouji[prev_day].erase(target_edge_idx2);
                kouji[next_day].insert(target_edge_idx2);
            }
        }

        route_select_value = xRnd(1, 100);

        // if(sw.GetTimeMS() > LIMIT_TIME){
        //     stop = true;
        //     break;
        // }
    }

    ansOutput(r, M);

    debugVL(sw.GetTimeMS());
    // debugVL(debugCnt);
    for(int i = 0; i < debugOut.size(); i++){
        double time = debugOut[i].first;
        string str;
        if(debugOut[i].second == 1){
            str = "CHANGE";
        }
        else{
            str = "NOT_CHANGE";
        }

        debugV(time);
        debug(str);
        debugWL();
    }

    return 0;
}