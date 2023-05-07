#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string str1;
    cin >> str1;

    string str2 = str1;
    cout << "最初" << '\n';
    cout << str1 << '\n';
    cout << str2 << '\n';

    cout << '\n';

    str2.at(0) = toupper(str2.at(0));
    cout << "代入演算子で渡す" << '\n';
    cout << str1 << '\n';
    cout << str2 << '\n';

    cout << '\n';
    
    cout << "多分コピーを作りたいならコンストラクタに渡した方が良さそう" << '\n';
    string str3(str1);
    str3.at(str3.size() - 1) = toupper(str3.at(str3.size() - 1));
    cout << str1 << '\n';
    cout << str3 << '\n';

    cout << '\n';

    cout << "str1に変更を加えたらどうなる？" << '\n';
    str1.at(0) = 'T';
    cout << str1 << '\n';
    cout << str2 << '\n';
    cout << str3 << '\n';

    return 0;
}