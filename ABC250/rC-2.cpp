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
    int N, Q;
    cin >> N >> Q;
    vector<int> val(N), pos(N);
    for(int i = 0; i < N; i++){
        val.at(i) = i;
        pos.at(i) = i;
    }

    while(Q--){
        int x;
        cin >> x;
        x--;

        int p0 = pos.at(x);
        int p1;
        if(p0 == N-1){
            p1 = p0 - 1;
        }
        else{
            p1 = p0 + 1;
        }
        int v = val.at(p1);
        swap(val.at(p0), val.at(p1));
        swap(pos.at(x), pos.at(v));
    }

    for(int i = 0; i < N; i++){
        cout << val.at(i) + 1;

        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;
}