#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

bool isOK(int x, vector<int> A){
    set<int> s;
    s.insert(0);
    for(int na : A){
        set<int> p;
        swap(s, p);
        for(int np : p){
            s.insert(np + na);
            s.insert(np - na);
        }
    }

    return s.count(x);
}

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> Ax, Ay;
    for(int i = 1; i < N; i++){
        if(i % 2 == 0){
            Ax.push_back(A.at(i));
        }
        else{
            Ay.push_back(A.at(i));
        }
    }

    x -= A.at(0);
    if(isOK(x, Ax) && isOK(y, Ay)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}