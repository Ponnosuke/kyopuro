#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

// i64乱数ジェネレーター
// myRnd32() よりこっちの方が高速な可能性が高い(ローカルでもAtCoderオンラインコンパイルでも)。
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
ui64 myRnd64(ui64 L, ui64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    ui64 ret = L + (rd() % (R - L + 1));

    return ret;
}

const vector<int> C_TABLE = {1, 2, 4, 8, 16, 32, 64, 128};

const ui64 seedL = 0, seedR = (1ULL << 63ULL) - 2 + (1ULL << 63ULL);

int main() {
    string textName;
    cout << "Text name :";
    cin >> textName;
    textName += ".txt";
    ofstream outputText(textName);

    for(int i = 0; i < 8; i++){
        int C = C_TABLE.at(i);
        for(int j = 0; j < 25; j++){
            outputText << myRnd64(seedL, seedR) << " " << 0 << " " << 0 << " " << C << '\n';
        }
    }

    outputText.close();
    cout << "The work has done!" << "\n";
}