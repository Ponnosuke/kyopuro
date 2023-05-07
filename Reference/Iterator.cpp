/*
コンテナを vec とする
itr  はイテレータを指す

vec.begin()  :  先頭の要素を指すイテレータ
vec.end()    :  末尾の要素の次 を指すイテレータ
distance(itr1, itr2)  :  itr1 を何回進めると itr2 に一致するかを返す
advance(itr, k)  イテレータを k　回進める (k に負の数も渡せる)
next(itr, k)  k 個先のイテレータを得る。 kは省略すると1になる
prev  k 個前のイテレータ。省略すると next と同様のはず
*/


#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    using pii = pair<int, int>;


    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int cnt = 0;
    // vec.begin()   .. 先頭の要素を指すイテレータ
    //  vec.end()  .... 末尾の要素の次を指すイテレータ
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << "vec[" << cnt << "] = " << *it << endl;
        cnt++;
    }
    cout << "\n";

    // イテレータの型はコンテナごとに定義されており複雑になることが多いので
    // auto で型指定をすると良い


    cout << "distance(vec.begin(), prev(vec.end()) = ";
    cout << distance(vec.begin(), prev(vec.end())) << endl;
    // distance(iterator1, iterator2)
    // iterator1 を何回進めると iterator2 に一致するか を返す
    cout << "\n";


    auto vecItr = vec.begin();
    cout << "*vecItr = " << *vecItr << endl;
    cout << "*next(vecItr, 3) = " << *next(vecItr, 3) << endl;
    cout << "*vecItr = " << *vecItr << endl;
    cout << "advance(vecItr, 3)" << endl;
    advance(vecItr, 3);
    cout << "*vecItr = " << *vecItr << endl;
    cout << "*next(vecItr) = " << *next(vecItr) << endl;
    cout << "*prev(vecItr) = " << *prev(vecItr) << endl;
    cout << "*vecItr = " << *vecItr << endl;


    vector<pii> a = {{1, 4}, {2, 5}, {3, 6}};
    auto itr = next(a.begin());
    cout << (itr->first) << ", " << (itr->second) << endl;
    // pair は std で定義されているクラス
    // first second のメンバ変数が定義されている、はず
    // イテレータ->メンバ変数, イテレータ->メンバ関数()
    // でイテレータが指す要素のメンバへアクセスできる
    // ちなみに  cout << (*itr).first << ", " << (*itr).second << endl; と書くのと同じ


    vector<int> b = {1, 2, 3, 5};
    // 3の要素を指すイテレータ
    auto itr2 = find(b.begin(), b.end(), 3);
    
    // もし存在しなければ、b.end()が返る
    if (itr2 == b.end()) {
        cout << "not found" << endl;
    } else {
        // itr2が添字の何番目を指すかを求める
        int idx = distance(b.begin(), itr2);
        cout << "b[" << idx << "] = " << *itr2 << endl;
    }


    vector<int> c = {1, 3, 4, 5, 9, 10};
    // 偶数であるような最初の要素を指すイテレータ
    auto itr3 = find_if(c.begin(), c.end(), [](int x) { return (x % 2 == 0); });
    if (itr3 == c.end()) {
        cout << "not found" << endl;
    } else {
        cout << *itr3 << endl;
    }


    // lower_bound(iterator1, iterator2, value)  
    // 指定した value 以上の最小の要素を探してその要素を指す iterator を返す
    // 見つからなかった場合は範囲の最後 (iterator2) を返す
    // map/set の場合はメンバ関数版の lower_bound を用いる方が高速
    // オブジェクト.lower_bound(itr1, itr2, value)
    // 計算量は コンテナの要素数を N として O(logN)
    vector<int> vecD = {8, 5, 3};
    sort(vecD.begin(), vecD.end());  // lower_boundを使うためにソートする
    
    // 5以上の最小の要素を指すイテレータ
    auto itr4 = lower_bound(vecD.begin(), vecD.end(), 5);
    if (itr4 == vecD.end()) {
        cout << "not found" << endl;
    } else {
        cout << *itr4 << endl;
    }
    
    // 6以上の最小の要素を指すイテレータ
    auto itr5 = lower_bound(vecD.begin(), vecD.end(), 6);
    if (itr5 == vecD.end()) {
        cout << "not found" << endl;
    } else {
        cout << *itr5 << endl;
    }


    // upper_bound は イテレータの範囲内から指定した値より大きな最小の要素を探して、
    // その要素を指すイテレータを返す。
    // 使い方とか計算量とかは lower_bound と同じ。
    // これも、 map/set の場合は メンバ関数版を使うのが良い

    return 0;
}