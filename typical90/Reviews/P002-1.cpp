#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

bool isOK(string str){
    int cnt = 0;
    for(auto ch : str){
        if(ch == '('){
            cnt++;
        }
        else{
            cnt--;
        }

        if(cnt < 0){
            return false;
        }
    }

    if(cnt == 0){
        return true;
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < (1 << N); i++){
        string str = "";
        for(int j = N - 1; j >= 0; j--){
            if((i & (1 << j)) == 0){
                str += '(';
            }
            else{
                str += ')';
            }
        }

        bool OK = isOK(str);
        if(OK){
            cout << str << '\n';
        }
    }

    return 0;
}