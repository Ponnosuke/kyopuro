// 競プロ典型90問  Problem027

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    set<string> mySet;
    for(int i = 0; i < N; i++){
        if(mySet.insert(S.at(i)).second){
            cout << i + 1 << endl;
        }
    }
    // pair<iterator, bool> insert(value_type&& y);
    /*
    set.insert() の返り値の型は pair<iterator, bool>
    first は新しく挿入された要素、またはすでに set に格納されていた同じ値の要素を指すイテレータを設定する
    second には要素が挿入されたときに true を、同じ値の要素が存在したときに false を設定する
    */

    return 0;  
}