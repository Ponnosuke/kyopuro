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

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N), B(N);
    for(i64 i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    vector<pair<double, i64>> vp;
    for(int i = 0; i < N; i++){
        double value = (double)A.at(i)/ (double)(A.at(i) + B.at(i));
        vp.emplace_back(value, i);
    }

    auto myGreater = [](pair<double, i64> p1, pair<double, i64> p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        else{
            return p1.first > p2.first;
        }
    };

    sort(vp.begin(), vp.end(), myGreater);

    for(int i = 0; i < N; i++){
        cout << vp.at(i).second + 1;

        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';
}