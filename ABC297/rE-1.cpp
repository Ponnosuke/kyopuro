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

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    Timer sw = Timer();

    set<i64> seen;
    priority_queue<i64, vector<i64>, greater<i64>> pq;
    seen.insert(0);
    pq.push(0);
    i64 ans;
    i64 cnt = -1;
    while(!pq.empty()){
        i64 v = pq.top();
        cnt++;
        if(cnt == K){
            ans = v;
            break;
        }
        pq.pop();

        for(int i = 0; i < N; i++){
            i64 nv = v + A.at(i);
            if(seen.count(nv)){
                continue;
            }
            else{
                seen.insert(nv);
            }
            pq.push(nv);
        }
    }

    cout << ans << '\n';

    debugVL(sw.GetTimeMS());
}