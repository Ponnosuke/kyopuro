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

    int factN = 1;
    for(int i = 2; i <= N; i++)  factN *= i;

    vector<vector<int>> seqList;
    vector<int> initList(N);
    iota(initList.begin(), initList.end(), 1);

    // debug
    // cout << 1 << endl;

    do{
        seqList.push_back(initList);
    } while (next_permutation(initList.begin(), initList.end()));

    // debug
    /*
    cout << 2 << endl;
    cout << "seqList.size() = " << seqList.size() << endl;
    cout << "seqList.at(0).size() = " << seqList.at(0).size() << endl;
    cout << "factN = " << factN << endl;
    */

    int a = -3389, b = 3391;
    for(int i = 0; i < factN; i++){
        if(seqList.at(i) == P) a = i;
        if(seqList.at(i) == Q) b = i;
    }

    // debug
    // cout << 3 << endl;

    cout << abs(a - b) << endl;


}