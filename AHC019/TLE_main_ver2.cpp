/*
    TLE 解
    このBFS の書き方だと良くないらしい

    高速化できた ver は main_ver2.cpp を参照
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

int ret_b_index(int D, int x, int y, int z){
    return x * D * D + y * D + z;
}

void print_output(int D, int ret_n, vector<vector<i64>> &b){
    int b_size = D*D*D;

    cout << ret_n << '\n';
    for(int i = 0; i < b_size; i++){
        cout << b.at(0).at(i);

        if(i < b_size - 1){
            cout << " ";
        }
    }
    cout << '\n';
    for(int i = 0; i < b_size; i++){
        cout << b.at(1).at(i);

        if(i < b_size - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return;
}

vector<int> dx = {1, -1, 0, 0, 0, 0};
vector<int> dy = {0, 0, 1, -1, 0, 0};
vector<int> dz = {0, 0, 0, 0, 1, -1};

struct Point{
    int x;
    int y;
    int z;

    Point(int ix, int iy, int iz) : x(ix), y(iy), z(iz){
    }

    Point(){
    }

    void Set(int ix, int iy, int iz){
        x = ix;
        y = iy;
        z = iz;

        return;
    }
};

void block_bfs(int D, vector<vector<char>> &f, vector<vector<char>> &r, int &n, vector<i64> &b){
    vector<vector<vector<bool>>> visited(D, vector<vector<bool>>(D, vector<bool>(D, false)));
    queue<Point> Q;

    for(int x = 0; x < D; x++){
        for(int y = 0; y < D; y++){
            for(int z = 0; z < D; z++){
                if(visited.at(x).at(y).at(z)){
                    continue;
                }
                if(f.at(z).at(x) == '0' || r.at(z).at(y) == '0'){
                    // この visited は、あってもなくても TLE するっぽい
                    // visited.at(x).at(y).at(z) = true;
                    continue;
                }

                Q.emplace(Point(x, y, z));
                n++;
                while(!Q.empty()){
                    Point v = Q.front();
                    Q.pop();
                    visited.at(v.x).at(v.y).at(v.z) = true;
                    b.at(ret_b_index(D, v.x, v.y, v.z)) = n;

                    for(int i = 0; i < 6; i++){
                        Point nv = Point(v.x + dx.at(i), v.y + dy.at(i), v.z + dz.at(i));
                        if(nv.x < 0 || D <= nv.x || nv.y < 0 || D <= nv.y || nv.z < 0 || D <= nv.z){
                            continue;
                        }
                        if(visited.at(nv.x).at(nv.y).at(nv.z)){
                            continue;
                        }
                        if(f.at(nv.z).at(nv.x) == '0' || r.at(nv.z).at(nv.y) == '0'){
                            continue;
                        }

                        Q.emplace(Point(nv.x, nv.y, nv.z));
                    }
                }
            }
        }
    }

    return;
}


int main() {
    // input
    i64 D;
    cin >> D;
    vector<vector<vector<char>>> f(2, vector<vector<char>>(D, vector<char>(D, 0)));
    vector<vector<vector<char>>> r(2, vector<vector<char>>(D, vector<char>(D, 0)));
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> f.at(0).at(i).at(j);
        }
    }
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> r.at(0).at(i).at(j);
        }
    }
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> f.at(1).at(i).at(j);
        }
    }
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            cin >> r.at(1).at(i).at(j);
        }
    }

    Timer sw = Timer();

    vector<vector<i64>> b(2, vector<i64>(D*D*D, 0));
    int n = 0;

    debugP();

    block_bfs(D, f.at(0), r.at(0), n, b.at(0));

    debugP();

    block_bfs(D, f.at(1), r.at(1), n, b.at(1));

    debugP();

    int ret_n = n;
    print_output(D, ret_n, b);

    debugVL(sw.GetTimeMS());
}