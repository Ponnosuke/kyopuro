/*
    嘘解法感ある
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // debug
    Timer sw = Timer();

    i64 N;
    cin >> N;
    map<vector<i64>, i64> mp;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        vector<i64> cnt(26, 0);
        for(auto ch : S){
            cnt[(int)(ch - 'a')]++;
        }

        mp[cnt]++;
    }

    i64 nume = 0;
    for(auto &[vec, cnt] : mp){
        if(cnt >= 2){
            nume += cnt*(cnt-1)/2;
        }
    }

    i64 deno = N*(N-1)/2;

    cout << fixed << setprecision(20);
    cout << (double)nume / (double)deno << '\n';

    debugVL(sw.GetTimeMS());

    return 0;
}