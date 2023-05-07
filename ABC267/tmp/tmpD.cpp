#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N, 0);
    for(auto &x : A)  cin >> x;

    vector<i64> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<i64>());

    vector<i64> B(M, -1);
    map<int, i64> mp;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(A.at(j) == sortedA.at(i)){
                mp[j] = A.at(j);
                break;
            }
        }
    }

    int index = 0;
    for(int i = 0; i < N; i++){
        if(mp.count(i)){
            B.at(index) = mp.at(i);
            index++;
        }
    }

    i64 sum = 0;
    for(int i = 0; i < M; i++){
        sum += (i+1) * B.at(i);
    }

    cout << sum << endl;
}