/*
    assert マクロ
    assert(condition)  :  condition が true であることを expression する
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

void isPositive(int x){
    assert(x > 0);

    return;
}

int main() {
    int num = 0;
    cin >> num;

    isPositive(num);

    cout << "True END" << '\n';

    return 0;
}