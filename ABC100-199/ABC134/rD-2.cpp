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
    int N;
    cin >> N;
    vector<int> a(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> a.at(i);
    }

    vector<int> b(N+1, 0);
    for(int i = N; i >= 1; i--){
        int sum = 0;
        for(int j = i*2; j <= N; j += i){
            sum ^= b.at(j);
        }
        b.at(i) = sum ^ a.at(i);
    }

    vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(b.at(i) == 1){
            ans.push_back(i);
        }
    }
    int size = ans.size();
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