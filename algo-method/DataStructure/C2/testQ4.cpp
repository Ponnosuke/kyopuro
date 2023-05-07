#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

class Timer{
    private:
        std::chrono::system_clock::time_point m_start;
    public:
        Timer() {
            m_start = std::chrono::system_clock::now();
        }
    public:
        void Restart(){
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
    Timer sw = Timer();
    const int N = 1e8;
    vector<int> A(N);   // A はサイズ N の vector
    for(int i = 0; i < N; ++i) {
        // A に適当な値を代入する
        A[i] = i;
    }

    double time = 0;
    sw.Restart();
    // A の末尾から 1 番目の要素を削除し続ける
    for(int i = 0; i < N - 1; ++i) {
        A.erase(A.end() - 2);
    }
    time = sw.GetTimeMS();

    // 念のため、A の要素数を出力する (問題なければ 1 と表示されるはず)
    cout << A.size() << endl;
    cout << fixed << setprecision(10);
    cout << "Time = " << time << endl;

	return 0;
}