#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    short int i;
    unsigned short int j;

    cout << "short int's the number of bit is : " << 8 * sizeof(short int) << "bits\n";
    cout << "unsigned short int's the number of bit is " << 8 * sizeof(unsigned short int) << "bits\n";

    i = -120;
    j = 65528;

    i = 8;
    j = 8;

    i = i - 10;
    j = j - 10;

    cout << "signed int i = " << i << '\n';
    cout << "unsigned int j = " << j << '\n';

    cout << '\n';
    cout << "2^16 = " << (1 << 16) << '\n';

    int tempJ = 65528;
    stack<int> binaryJ;
    while(tempJ != 1){
        binaryJ.push(tempJ % 2);
        tempJ /= 2;
    }
    binaryJ.push(tempJ);
    int flag = 0;
    while(!binaryJ.empty()){
        cout << binaryJ.top() << " ";
        flag++;
        if(flag % 4 == 0){
            cout << " ";
        }
        binaryJ.pop();
    }
    cout << '\n';

    int tempJ2 = 65534;
    stack<int> binaryJ2;
    while(tempJ2 != 1){
        binaryJ2.push(tempJ2 % 2);
        tempJ2 /= 2;
    }
    binaryJ2.push(tempJ2);
    flag = 0;
    while(!binaryJ2.empty()){
        cout << binaryJ2.top() << " ";
        flag++;
        if(flag % 4 == 0){
            cout << " ";
        }
        binaryJ2.pop();
    }
    cout << '\n';
}