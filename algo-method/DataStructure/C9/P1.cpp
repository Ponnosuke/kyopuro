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

void rec(int v, vector<int> &l, vector<int> &r){
    if(l.at(v) != -1){
        rec(l.at(v), l, r);
    }

    cout << v << " ";

    if(r.at(v) != -1){
        rec(r.at(v), l, r);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> l(N), r(N);
    for(int i = 0; i < N; i++){
        cin >> l.at(i) >> r.at(i);
    }

    int root = 0;
    rec(root, l, r);
    cout << endl;

    return 0;
}