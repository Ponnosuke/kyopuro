/*
    ver6

    大きいのと小さいのを合わせていってみる。
    get_limit = (myRnd64(1, K) の期待値)
    修正版
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

struct Edge {
    int v1;
    int v2;
    int w;
    int index;

    void Set(int _v1, int _v2, int _w, int _index){
        v1 = _v1;
        v2 = _v2;
        w = _w;
        index = _index;
    }

    /*
    Edge(int e1, int e2, int w) : e1(e1), e2(e2), w(w){
    }
    */
};

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

int main() {
    Timer sw = Timer();

    int N, M, D, K;
    cin >> N >> M >> D >> K;
    vector<Edge> edges(M);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.at(i).Set(u, v, w, i+1);
    }

    /*
    debugWL(debug2);
    debugWL(v1 v2 w);
    for(int i = 0; i < M; i++){
        debug(edges.at(i).v1);
        debug(edges.at(i).v2);
        debug(edges.at(i).w);
        debugWL();
    }
    debugWL();
    */

    vector<int> x(N, 0), y(N, 0);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i);
    }

    // w が大きい順
    auto greater_w = [](Edge E1, Edge E2){
        return E1.w > E2.w;
    };
    sort(edges.begin(), edges.end(), greater_w);
    deque<int> index_deq;
    for(int i = 0; i < M; i++){
        index_deq.push_back(edges.at(i).index);
    }

    /*
    debugWL(debug);
    debugWL(w);
    int debug_max = -1;
    int debug_min = M+10;
    for(int i = 0; i < M; i++){
        debug_max = max(debug_max, edges.at(i).index);
        debug_min = min(debug_min, edges.at(i).index);
    }
    debugVL(M);
    debugV(debug_max);
    debugVL(debug_min);
    debugWL();
    */

    // debug
    debugWL(index_deq);
    set<int> debug_set;
    for(int i = 0; i < index_deq.size(); i++){
        assert(!debug_set.count(index_deq.at(i)));
        debug_set.insert(index_deq.at(i));
        debug(index_deq.at(i));
    }
    debugWL();

    vector<int> r(M, -99999);
    vector<int> dayCnt(D, 0);
    int get_limit;
    int limit_add = 0;
    bool stop = false;

    // debug
    debugWL(init index_deq size);
    debugVL(index_deq.size());
    debugWL();

    while(!index_deq.empty()){

        debugWL(-------------------------------------------------------);

        get_limit = (K+1 + limit_add) / 2;
        limit_add = 1 - limit_add;


        int cnt_flag = 0;
        for(int day = 0; day < D; day++){

            debugWL(point146);
            debugVL(day);

            while(get_limit > 0){
                
                debugWL(point150);

                int now_index;
                if(get_limit % 2 == 0){

                    debugWL(routeA);

                    now_index = index_deq.back();
                }
                else{

                    debugWL(routeB);

                    now_index = index_deq.front();
                }

                if(dayCnt.at(day) < K){

                    debugWL(routeAA);
                    if(r.at(now_index - 1) != -99999){
                        debugVL(r.at(now_index - 1));
                    }
                    assert(r.at(now_index-1) == -99999);


                    r.at(now_index-1) = day + 1;
                    dayCnt.at(day)++;

                    if(get_limit % 2 == 0){

                        debugWL(popA);

                        index_deq.pop_back();
                        get_limit--;
                    }
                    else{

                        debugWL(popB);

                        index_deq.pop_front();
                        get_limit--;
                    }
                }
                else{

                    debugWL(routeBB);

                    break;
                }


                if(index_deq.empty()){
                    stop = true;
                    break;
                }

                debugVL(index_deq.size());
                debugWL();
            }

            if(stop){
                break;
            }

            debugWL(point222);
        }


        // debug
        bool NG = true;
        for(int i = 0; i < D; i++){
            bool tmp = false;
            if(dayCnt.at(i) >= K){
                tmp = true;
            }

            NG &= tmp;
        }
        if(NG){
            debugWL(r);
            for(int i = 0; i < M; i++){
                debug(r.at(i));
            }
            debugWL();
            debugWL(dayCnt);
            for(int i = 0; i < D; i++){
                debug(dayCnt.at(i));
            }
            debugWL();
        }
        assert(!NG);

        if(stop){
            break;
        }
    }

    ansOutput(r, M);

    double time = sw.GetTimeMS();
    debugVL(time);

    return 0;
}