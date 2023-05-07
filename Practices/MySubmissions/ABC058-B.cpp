#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string O, E;
    cin >> O >> E;

    for(int i = 0; i < E.size(); i++){
        cout << O.at(i);
        cout << E.at(i);
    }

    if(O.size() > E.size()){
        cout << O.at(O.size() - 1);
    }

    cout << "\n";

    return 0;
}