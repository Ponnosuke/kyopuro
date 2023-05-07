#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    if(S.size() != 8){
        cout << "No" << '\n';
        return 0;
    }

    char iniS = S.at(0), endS = S.at(S.size() - 1);
    string midS = S.substr(1, 6);

    // debug
    // cerr << iniS << " " << endS << " " << midS << '\n';

    bool OK1 = false;
    int numS = 0;
    for(int i = 0; i < midS.size(); i++){
        char ch = midS.at(i);
        if('0' <= ch && ch <= '9'){
            numS += ch - '0';

            if(i < midS.size() - 1){
                numS *= 10;
            }
        }
        else{
            cout << "No" << '\n';
            return 0;
        }
    }

    // debug
    // cerr << "L36" << '\n';

    if(numS < 100000 || 999999 < numS){
        cout << "No" << '\n';
        return 0;
    }

    // debug
    // cerr << "L44" << '\n';

    if('A' <= iniS && iniS <= 'Z' && 'A' <= endS && endS <= 'Z'){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }

    return 0;
}