#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;

    bool big = false, small = false;
    for(auto ch : S){
        if(isupper(ch)){
            big = true;
        }
        else{
            small = true;
        }
    }

    bool diff = true;
    set<char> chSet;
    for(auto ch : S){
        if(chSet.count(ch)){
            diff = false;
            break;
        }
        else{
            chSet.insert(ch);
        }
    }

    if(big && small && diff){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}