#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    string S;
    cin >> S;
    set<int> mustNum;
    for(int i = 0; i < 10; i++){
        if(S.at(i) == 'o')  mustNum.insert(i);
    }

    int cnt = 0;
    for(int i = 0; i <= 9999 ; i++){
        bool mustOK = true;
        bool OK = true;
        int dig1, dig2, dig3, dig4;
        int tmp = i;
        set<int> digs;
        dig1 = tmp%10;
        tmp/=10;
        digs.insert(dig1);
        dig2 = tmp%10;
        tmp/=10;
        digs.insert(dig2);
        dig3 = tmp%10;
        tmp/=10;
        digs.insert(dig3);
        dig4 = tmp%10;
        digs.insert(dig4);

        vector<int> digvec = {dig1, dig2, dig3, dig4};


        for(auto value : mustNum){
            if(!(digs.count(value))){
                mustOK = false;
                break;
            }
        }

        if(!(mustOK))  continue;

        for(auto value : digvec){
            if(S.at(value) == 'x'){
                OK = false;
                break;
            }
        }

        if(mustOK && OK) cnt++;

    }

    cout << cnt << endl;
}