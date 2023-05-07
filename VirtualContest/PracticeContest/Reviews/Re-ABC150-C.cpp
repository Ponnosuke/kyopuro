#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    
    vector<int> P(N), Q(N);
    for(auto &x:P) cin >> x;
    for(auto &x:Q) cin >> x;

    vector<int> vec(N);
    iota(vec.begin(), vec.end(), 1);

    int a = -3389, b = 3391;
    int index = 0;
    do{
        if(vec == P) a = index;
        if(vec == Q) b = index;

        index++;
    } while (next_permutation(vec.begin(), vec.end()));

    cout << abs(a - b) << endl;


}