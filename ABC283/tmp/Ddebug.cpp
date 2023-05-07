#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// i64乱数ジェネレーター
// [L, R] を満たす int64_t 型のランダムな整数を返す
// ただし、 mt19937_64 は uint64_t 型を返していることに注意
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}


// int乱数ジェネレーター
// [L, R] を満たす int 型のランダムな整数を返す
// ただし、mt19937 は uint32_t 型を返していることに注意
int myRnd32(int L, int R){
    random_device seedGen;
    mt19937 rd(seedGen());

    int ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}

string testCaseGen(int strSize){
    string ret = "(";
    int lrCnt = 1;
    for(int i = 0; i < strSize; i++){
        int flag = myRnd32('a' + 0,'z' + 26 );
        if('z' < flag && flag <= 'z' + 13){
            ret += '(';
            lrCnt++;
        }
        else if('z' + 13 < flag && flag <= 'z' + 26){
            if(lrCnt < 1){
                ret += '(';
                continue;
            }
            ret += ')';
            lrCnt--;
        }
        else{
            ret += (char)(flag);
        }
    }

    while(lrCnt > 0){
        ret += ')';
        lrCnt--;
    }

    return ret;
}

const int NUM_OF_CASE = 10;

int main() {    
    string textName;
    int strSize;
    cout << "TextName strSize:" << '\n';
    cin >> textName >> strSize;
    textName += ".txt";

    ofstream outputText(textName);
    for(int i = 0; i < NUM_OF_CASE; i++){
        outputText << testCaseGen(strSize) << "\n";
    }

    outputText.close();

    cout << "The work has done!" << "\n";

    return 0;
}