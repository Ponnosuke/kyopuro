#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    // debug
    // cerr << (int)('(') << '\n';
    // cerr << (int)(')') << '\n';
    // '(' = 40
    // ')' = 41
    
    if(N % 2 != 0){
        return 0;
    }
    else{
        string str = "";
        for(int i = 0; i < (N/2) - 1; i++){
            str += '(';
        }
        for(int i = 0; i < (N/2) - 1; i++){
            str += ')';
        }

        do{
            int checkNum = 0;
            bool OK = true;
            string tmpStr = '(' + str + ')';
            for(auto ch : tmpStr){
                if(ch == '('){
                    checkNum++;
                }
                else{
                    checkNum--;
                }

                if(checkNum < 0){
                    OK = false;
                    break;
                }
            }

            if(OK){
                cout << tmpStr << '\n';
            }
        }
        while(next_permutation(str.begin(), str.end()));
    }

    return 0;
}