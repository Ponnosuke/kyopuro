#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    deque<int> deck;
    for(int i = 0; i < Q; i++){
        int t, x;
        cin >> t >> x;

        if(t == 1){
            deck.push_front(x);
        }
        if(t == 2){
            deck.push_back(x);
        }
        if(t == 3){
            cout << deck.at(x-1) << endl;
        }
    }


}