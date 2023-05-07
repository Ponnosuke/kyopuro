/*
    deque を用いた尺取り法。queue でも同様の実装をできる

    180ms
*/

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
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<i64> nums;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            i64 num1 = A.at(i), num2 = A.at(j);
            nums.push_back(num1*num1 + num2*num2);
        }
    }
    sort(nums.begin(), nums.end());
    i64 nSize = nums.size();
    deque<i64> dq;
    for(int i = 0; i < nSize; i++){
        dq.push_back(nums.at(i));
    }

    bool OK = false;
    for(int i = 0; i < nSize; i++){
        i64 now = nums.at(i);

        while(!dq.empty() && (dq.back() + now > M)){
            dq.pop_back();
        }

        if(!dq.empty() && (now + dq.back() == M)){
            OK = true;
            break;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';

    return 0;
}