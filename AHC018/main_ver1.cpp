/*
    ver 1

    一つずつランダムなパワーで終わるまで掘削
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

int main() {
    int N, W, K, C;
    cin >> N >> W >> K >> C;
    vector<int> a(W, 0), b(W, 0);
    for(int i = 0; i < W; i++){
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> c(K, 0), d(K, 0);
    for(int i = 0; i < K; i++){
        cin >> c.at(i) >> d.at(i);
    }

    int y, x, P = 1000;
    int now_index = 0;
    int r;
    while(true){
        Pos now_pos = index_to_pos(now_index, N);
        y = now_pos.y;
        x = now_pos.x;

        cout << y << " " << x << " " << P << endl;
        cin >> r;

        if(r == 0){
            continue;
        }
        else if(r == 1){
            assert(now_index <= pos_to_index(Pos(N-1, N-1), N));
            now_index++;
        }
        else if(r == 2){
            exit(0);
        }
        else{
            exit(0);
        }
    }

    return 0;
}