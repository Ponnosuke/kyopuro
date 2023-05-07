/*
    テストケースを作るためのテキストファイルの出力
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string textName;
    cout << "Text name :";
    cin >> textName;
    textName += ".txt";

    ofstream outputText(textName);
    outputText << "HelloP!" << "\n";

    outputText.close();

    cout << "The work has done!" << "\n";

    return 0;
}