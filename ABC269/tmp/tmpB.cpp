#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    vector<string> S(10);
    for(int i = 0; i < 10; i++)  cin >> S.at(i);

    bool flagA, flagB, flagC, flagD;
    flagA = false;
    flagB = false;
    flagC = false;
    flagD = false;
    int A = -1, B = -1, C = -1, D = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(S.at(i).at(j) == '#' && !flagC){
                A = i + 1;
                C = j + 1;
                flagA = true;
                flagC = true;
                
                // cout << i << " " << j << endl;
            }
            
            if((S.at(i).at(j) == '.' ) && flagC){
                D = j;
                flagD = true;
                break;
            }

            if(flagC && j >= 9){
                D = 10;
                flagD = true;
            }
        }
        if(flagD)  break;
    }

    for(int i = A - 1; i < 10; i++){
        if(S.at(i).at(C-1) == '.'){
            B = i;
            break;
        }

        if(i >= 9){
            B = 10;
        }
    }

    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}