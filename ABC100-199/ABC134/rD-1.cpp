#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
using int64 = int64_t;
using uint64 = uint64_t;

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
    int64 N;
    cin >> N;
    vector<int64> a(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> a.at(i);
    }

    vector<int64> b(N+1, 0);
    for(int i = N; i >= 1; i--){
        int64 sum = 0;
        for(int j = i*2; j <= N; j += i){
            sum += b.at(j);
            sum %= 2;
        }
        if(sum != a.at(i)){
            b.at(i) = 1;
        }
    }
    
    vector<int64> ans;
    for(int i = 1; i <= N; i++){
        if(b.at(i) != 0){
            ans.push_back(i);
        }
    }
    int64 size = ans.size();
    cout << size << '\n';
    for(int i = 0; i < size; i++){
        cout << ans.at(i);

        if(i < size - 1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}