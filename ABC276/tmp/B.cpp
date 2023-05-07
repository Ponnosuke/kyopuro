#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, set<int>> mp;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        // A--;
        // B--;
        mp[A].insert(B);
        mp[B].insert(A);
    }

    for(int i = 1; i <= N; i++){
        if(mp.count(i)){
            cout << mp.at(i).size() << " ";

            for(auto it = mp.at(i).begin(); it != mp.at(i).end(); it++){
                cout << *it;
                if(it == prev(mp.at(i).end())){
                    cout << '\n';
                }
                else{
                    cout << " ";
                }
            }
        }
        else{
            cout << 0 << '\n';
        }
    }

}