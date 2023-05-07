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
    vector<vector<i64>> a(N);
    for(int i = 0; i < N; i++){
        i64 L;
        cin >> L;

        for(int j = 0; j < L; j++){
            i64 iA;
            cin >> iA;
            a.at(i).push_back(iA);
        }
    }

    sort(a.begin(), a.end());
    // debug
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < a.at(i).size(); j++){
    //         debug(a.at(i).at(j));
    //     }
    //     debugWL();
    // }

    i64 cnt = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            cnt++;
            continue;
        }

        int preSize = a.at(i-1).size(), nowSize = a.at(i).size();
        if(preSize != nowSize){
            cnt++;
        }
        else{
            bool diff = false;
            for(int j = 0; j < preSize; j++){
                if(a.at(i-1).at(j) != a.at(i).at(j)){
                    diff = true;
                    break;
                }
            }

            if(diff){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}