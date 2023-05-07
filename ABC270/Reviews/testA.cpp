#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    vector<vector<int>> test(3);
    test.at(0).push_back(A);
    test.at(0).push_back(B);
    test.at(1).push_back(C);
    test.at(2).push_back(D);
    test.at(2).push_back(E);
    test.at(2).push_back(F);

    deque<int> deq;

    for(int i = 0; i < 3; i++){
        for(auto num : test.at(i)){
            deq.push_back(num);
        }
    }

    while(!deq.empty()){
        cout << deq.front();
        deq.pop_front();
        if(deq.empty()){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
    
    return 0;
}