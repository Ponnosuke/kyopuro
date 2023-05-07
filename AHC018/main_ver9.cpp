/*
    ver 9

    ver 8 から継承
    まずは近くの水源への距離が最も短い家と水源をつなぐ。
    そこからその家A からまだ水が届いていない家B を探し、家Bから水源への距離と家Bの近くの
    水が通っている家への距離のどちらが近いかを調べて近い方から水を伸ばす

    C > 64 の時は、
    壊した際のパワーを次の初期パワーにする。
    何回か 1 回で壊せるのが続いたらリセット

    ver 8 と違い C が大きい場合 P_ini = 120 とした
    
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
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif


/*
    "uint32_t xor128()" is from shindannin's code.
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


struct Pos{
    int y, x;
    
    Pos(int iy, int ix) : y(iy), x(ix) {
    }

    Pos(){
    }

    void Set(int iy, int ix){
        y = iy;
        x = ix;

        return;
    }
};

int pos_to_index(Pos P, int N){
    return N * P.y + P.x;
}

Pos index_to_pos(int idx, int N){
    Pos ret = Pos(idx / N, idx % N);
    return ret;
}

int cal_distance(Pos p1, Pos p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y); 
}


/*
    The original of this class is from "sample_submission.cpp" of AHC018.
    And I've edited it a little.
*/
enum {
    NOT_BROKEN = 0,
    BROKEN = 1,
    FINISH = 2,
    INVALID = -1,
};

const int INT_INF = (1 << 30);

int main() {

    int N, W, K, C;
    cin >> N >> W >> K >> C;
    // vector<int> a(W, 0), b(W, 0);
    vector<Pos> water(W, Pos());
    for(int i = 0; i < W; i++){
        int ia, ib;
        cin >> ia >> ib;
        // a.at(i) = ia;
        // b.at(i) = ib;

        water.at(i).Set(ia, ib);
    }
    // vector<int> c(K, 0), d(K, 0);
    vector<Pos> house(K, Pos());
    vector<vector<int>> is_house(N, vector<int>(N, -1));  // [y][x], 0以上なら家がある
    for(int i = 0; i < K; i++){
        int ic, id;
        cin >> ic >> id;
        // c.at(i) = ic;
        // d.at(i) = id;

        is_house.at(ic).at(id) = i;
        house.at(i).Set(ic, id);
    }

    vector<int> house_nearest_water_index(K, 0);  // [i] := house[i] の一番近い water の index
    vector<int> house_nearest_water_dist(K, 0); // [i] := house[i] の一番近い water への距離
    vector<vector<pair<int, int>>> house_dest_cand_order(K); 
    // [i][j] := house[i] から j+1 番目に近い house または water
    // first: dist, second: index
    // index が -1 の時、水を示す

    int to_water_house_index = -1; // 家の中で最も水が近い家の index
    int judge_dist = INT_INF;
    for(int i = 0; i < K; i++){
        int now_dist = INT_INF, now_index = -1;
        for(int j = 0; j < W; j++){
            if(now_dist > cal_distance(house.at(i), water.at(j))){
                now_dist = cal_distance(house.at(i), water.at(j));
                now_index = j;
            }
        }

        house_nearest_water_index.at(i) = now_index;
        house_nearest_water_dist.at(i) = now_dist;

        if(now_dist < judge_dist){
            to_water_house_index = i;
        }
    }

    for(int i = 0; i < K; i++){
        int now_dist = house_nearest_water_dist.at(i);
        house_dest_cand_order.at(i).emplace_back(make_pair(now_dist, -1));
    }

    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            if(i == j){
                continue;
            }

            int now_dist = cal_distance(house.at(i), house.at(j));
            house_dest_cand_order.at(i).emplace_back(make_pair(now_dist, j));
            house_dest_cand_order.at(j).emplace_back(make_pair(now_dist, i));
        }
    }

    for(int i = 0; i < K; i++){
        sort(house_dest_cand_order.at(i).begin(), house_dest_cand_order.at(i).end());
    }

    // debug
    for(int i = 0; i < K; i++){
        int vec_size = house_dest_cand_order.at(i).size();
        for(int j = 1; j < vec_size; j++){
            assert(house_dest_cand_order.at(i).at(j).first >= house_dest_cand_order.at(i).at(j-1).first);
        }
    }

    // int y, x; 
    int P_ini = 50;
    int P_add = 0;
    if(C == 1){
        P_ini = 25;
    }
    else if(C == 2){
        P_ini = 50;
    }
    else if(C == 4){
        P_ini = 80;
    }
    else if(C == 8){
        P_ini = 100;
    }
    else{
        P_ini = 120;
    }
    int P = P_ini;

    int r;


    // cerr << "C = " << C << " ";
    // cerr << "P = " << P << '\n';

    vector<vector<int>> field(N, vector<int>(N, NOT_BROKEN));
    vector<bool> ok_house(K, false);

    int from_house_index = to_water_house_index;
    int dest_house_index = to_water_house_index;

    bool water_step = true;

    int pre_pre_cnt = 0, pre_cnt = 0, now_cnt = 0;
    int now_sum_P = 0;
    //int pre_pre_sum_P = 0, pre_sum_P = 0;
    int P_next = P_ini;
    
    while(true){
        Pos now_pos = house.at(from_house_index);
        Pos dest_pos;
        P = P_next;

        if(water_step){            

            debugWL(water_step);

            // dest_house_index = from_house_index;
            int to_water_index = house_nearest_water_index.at(dest_house_index);
            Pos to_water_pos = water.at(to_water_index);
            dest_pos.Set(to_water_pos.y, to_water_pos.x);
            
            water_step = false;
        }
        else{

            debugWL(not_water_step);

            Pos to_house_pos = house.at(dest_house_index);
            
            dest_pos.Set(to_house_pos.y, to_house_pos.x);            
        }

        debugV(now_pos.y);
        debugVL(now_pos.x);
        debugV(dest_pos.y);
        debugVL(dest_pos.x);

        int unit_vec_y;
        int unit_vec_x;
        bool OK_y = false, OK_x = false;
        if(abs(dest_pos.y - now_pos.y) == 0){
            unit_vec_y = 0;
            OK_y = true;
        }
        else{
            unit_vec_y = (dest_pos.y - now_pos.y) / abs(dest_pos.y - now_pos.y);
        }
        if(abs(dest_pos.x - now_pos.x) == 0){
            unit_vec_x = 0;
            OK_x = true;
        }
        else{
            unit_vec_x = (dest_pos.x - now_pos.x) / abs(dest_pos.x - now_pos.x);
        }
        Pos unit_vec = Pos(unit_vec_y, unit_vec_x);

        while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
            if(now_pos.y == dest_pos.y){
                OK_y = true;
                break;
            }
            now_pos.y += unit_vec.y;
        }
        while(!OK_y){
            cout << now_pos.y << " " << now_pos.x << " " << P << endl;

            // debug
            cerr << now_pos.y << " " << now_pos.x << " " << P << endl;

            cin >> r;

            if(r == NOT_BROKEN){
                now_sum_P += P;
                now_cnt++;
                if(P > P_ini){
                    P = P_ini;
                }

                continue;
            }
            else if(r == BROKEN){
                field.at(now_pos.y).at(now_pos.x) = BROKEN;

                now_cnt++;
                if(now_cnt == 1){
                    now_sum_P = P;
                }
                P_next = min(now_sum_P, 5000);
                if(pre_pre_cnt == 1 && pre_cnt == 1 && now_cnt == 1){
                    P_next = P_ini;
                }
                if(C < 64){
                    P = P_ini;
                }
                else{
                    P = P_next;
                }
                pre_pre_cnt = pre_cnt;
                pre_cnt = now_cnt;
                now_cnt = 0;
                now_sum_P = 0;

                int judge_cnt = is_house.at(now_pos.y).at(now_pos.x);
                if(judge_cnt >= 0){
                    ok_house.at(judge_cnt) = true;
                }

                if(now_pos.y == dest_pos.y){
                    OK_y = true;
                    break;
                }
                else{
                    while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
                        if(now_pos.y == dest_pos.y){
                            OK_y = true;
                            break;
                        }
                        now_pos.y += unit_vec.y;

                    }
                }
            }
            else if(r == FINISH){
                exit(0);
            }
            else{
                exit(0);
            }
        }

        

        while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
            if(now_pos.x == dest_pos.x){
                OK_x = true;
                break;
            }
            now_pos.x += unit_vec.x;
        }

        P = P_next;

        while(!OK_x){

            cout << now_pos.y << " " << now_pos.x << " " << P << endl;

            // debug
            cerr << now_pos.y << " " << now_pos.x << " " << P << endl;

            cin >> r;

            if(r == NOT_BROKEN){
                now_sum_P += P;
                now_cnt++;
                if(P > P_ini){
                    P = P_ini;
                }

                continue;
            }
            else if(r == BROKEN){
                field.at(now_pos.y).at(now_pos.x) = BROKEN;
                
                now_cnt++;
                if(now_cnt == 1){
                    now_sum_P = P;
                }
                P_next = min(now_sum_P, 5000);
                if(pre_pre_cnt == 1 && pre_cnt == 1 && now_cnt == 1){
                    P_next = P_ini;
                }
                if(C < 64){
                    P = P_ini;
                }
                else{
                    P = P_next;
                }
                pre_pre_cnt = pre_cnt;
                pre_cnt = now_cnt;
                now_cnt = 0;
                now_sum_P = 0;

                int judge_cnt = is_house.at(now_pos.y).at(now_pos.x);
                if(judge_cnt >= 0){
                    ok_house.at(judge_cnt) = true;
                }

                if(now_pos.x == dest_pos.x){
                    OK_x = true;
                    break;
                }
                else{                    
                    while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
                        if(now_pos.x == dest_pos.x){
                            OK_x = true;
                            break;
                        }
                        now_pos.x += unit_vec.x;

                    }                
                }
            }
            else if(r == FINISH){
                exit(0);
            }
            else{
                exit(0);
            }
        }

        if(OK_y && OK_x){
            ok_house.at(dest_house_index) = true;
        }

        assert(OK_y && OK_x);

        from_house_index = dest_house_index;
        int vec_size = house_dest_cand_order.at(from_house_index).size();
        for(int idx = 0; idx < vec_size; idx++){
            int dest_cand_idx = house_dest_cand_order.at(from_house_index).at(idx).second;
            if(dest_cand_idx == -1){
                continue;
            }
            else if(!ok_house.at(dest_cand_idx)){
                dest_house_index = dest_cand_idx;
                int vec_size2 = house_dest_cand_order.at(dest_house_index).size();
                for(int jdx = 0; jdx < vec_size2; jdx++){
                    int from_cand_idx = house_dest_cand_order.at(dest_house_index).at(jdx).second;

                    // debug
                    debugV(house.at(dest_house_index).y);
                    debugVL(house.at(dest_house_index).x);
                    int debug_dist = house_dest_cand_order.at(dest_house_index).at(jdx).first;
                    debugV(debug_dist);
                    debugVL(from_cand_idx);
                    if(from_cand_idx != -1){
                        debugV(house.at(from_cand_idx).y);
                        debugVL(house.at(from_cand_idx).x);
                    }

                    if(from_cand_idx == -1){
                        from_house_index = dest_house_index;
                        water_step = true;
                        break;
                    }

                    if(ok_house.at(from_cand_idx)){
                        from_house_index = from_cand_idx;
                        break;
                    }
                }
                break;
            }
        }

        debugWL();
    }

    return 0;
}