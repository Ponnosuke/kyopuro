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

i64 posToIndex(i64 x, i64 y, i64 N){
    return y*N + x;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    atcoder::dsu uf(N);

    int index = 0;
    i64 nowX = 200000, nowY = 200000;
    map<pair<i64, i64>, i64> idx;
    idx[make_pair(nowX, nowY)] = index;
    index++;
    bool flag = false;
    for(int i = 0; i < N; i++){
        i64 preX = nowX, preY = nowY;
        if(S.at(i) == 'R'){
            nowX += 1;
        }
        if(S.at(i) == 'L'){
            nowX -= 1;
        }
        if(S.at(i) == 'U'){
            nowY += 1;
        }
        if(S.at(i) == 'D'){
            nowY -= 1;
        }

        if(!idx.count(make_pair(nowX, nowY))){
            idx[make_pair(nowX, nowY)] = index;
            index++;
        }
        else{
            flag = true;
            break;
        }

        // i64 preIdx = idx.at(make_pair(preX, preY));
        // i64 nowIdx = idx.at(make_pair(nowX, nowY));
    }

    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}