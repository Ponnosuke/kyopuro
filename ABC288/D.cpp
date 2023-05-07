#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

map<int, i64> memo;
i64 f(i64 index, vector<i64> &A){
    if(index == 0){
        return 0;
    }
    if(index == 1){
        return -(A.at(0) + f(index - 1, A));
    }

    if(memo.count(index)){
        return memo.at(index);
    }

    i64 ret = 0;
    ret = -(A.at(index-2) + f(index-2, A)) - (A.at(index-1) + f(index-1, A));
    memo[index] = ret;

    return ret;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int Q;
    cin >> Q;

    debugWL(pointA);

    while(Q--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        i64 flagSum = 0;

        debugWL(pointB);

        if(l-2 >= 0)  flagSum += (A.at(l-2) + f(l-2, A));
        if(l-1 >= 0)  flagSum += (A.at(l-1) + f(l-1, A)) * 2;
        flagSum += 2 * f(l, A);
        i64 num1, num2, num3;
        num1 = A.at(r) + f(r, A) - flagSum;
        if(r-1 < N)  num2 = A.at(r-1) + f(r-1, A) - flagSum;
        if(r-2  < N)  num3 = A.at(r-2) + f(r-2, A) - flagSum;

        debugWL(pointC);

        bool OK1 = (num1 == num2);
        bool OK2 = (num2 == num3);
        if((num1 + num2 + num3) % K == 0 && OK1 && OK2){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }

    }
}