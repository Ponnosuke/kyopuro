/*
    ver 3

    ver 2 から継承
    一番近い水から家にかけて、y方向に一直線に進み、その後x方向に一直線に進む
    
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
    for(int i = 0; i < K; i++){
        int ic, id;
        cin >> ic >> id;
        // c.at(i) = ic;
        // d.at(i) = id;

        house.at(i).Set(ic, id);
    }

    vector<int> nearest_water_index(K, 0);
    for(int i = 0; i < K; i++){
        int now_dist = INT_INF, now_index = -1;
        for(int j = 0; j < W; j++){
            if(now_dist > cal_distance(house.at(i), water.at(j))){
                now_dist = cal_distance(house.at(i), water.at(j));
                now_index = j;
            }
        }

        nearest_water_index.at(i) = now_index;
    }



    // int y, x; 
    int P = 100;
    int r;
    vector<vector<int>> field(N, vector<int>(N, NOT_BROKEN));
    for(int house_index = 0; house_index < K; house_index++){
        int water_index = nearest_water_index.at(house_index);
        Pos now_house = house.at(house_index), now_water = water.at(water_index);

        Pos now_pos = Pos(now_water.y, now_water.x);
        // int vec_y = now_house.y - now_water.y;
        // int vec_x = now_house.x - now_water.x;
        int unit_vec_y = (now_house.y - now_water.y) / abs(now_house.y - now_water.y);
        int unit_vec_x = (now_house.x - now_water.x) / abs(now_house.x - now_water.x);
        bool OK_y = false, OK_x = false;
        while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
            if(now_pos.y == now_house.y){
                OK_y = true;
                break;
            }
            now_pos.y += unit_vec_y;
        }
        while(!OK_y){
            cout << now_pos.y << " " << now_pos.x << " " << P << endl;
            cin >> r;

            debugV(now_pos.y);
            debugV(now_pos.x);
            debugVL(r);

            if(r == NOT_BROKEN){
                continue;
            }
            else if(r == BROKEN){
                field.at(now_pos.y).at(now_pos.x) = BROKEN;

                if(now_pos.y == now_house.y){

                    debugP();

                    OK_y = true;
                    break;
                }
                else{

                    debugP();

                    while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
                        now_pos.y += unit_vec_y;
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

        debugP();

        while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
            if(now_pos.x == now_house.x){
                OK_x = true;
                break;
            }
            now_pos.x += unit_vec_x;
        }
        while(!OK_x){

            debugV(now_pos.y);
            debugV(now_pos.x);
            debugVL(r);

            cout << now_pos.y << " " << now_pos.x << " " << P << endl;
            cin >> r;

            if(r == NOT_BROKEN){
                continue;
            }
            else if(r == BROKEN){
                field.at(now_pos.y).at(now_pos.x) = BROKEN;

                if(now_pos.x == now_house.x){

                    debugP();

                    OK_x = true;
                    break;
                }
                else{

                    debugP();

                    while(field.at(now_pos.y).at(now_pos.x) == BROKEN){
                        now_pos.x += unit_vec_x;
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
    }

    return 0;
}