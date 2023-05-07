#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        bool div3 = (i % 3 == 0);
        bool div5 = (i % 5 == 0);
        
        if(div3 && div5){
            cout << "FizzBuzz" << endl;
        }
        else if(div3){
            cout << "Fizz" << endl;
        }
        else if(div5){
            cout << "Buzz" << endl;
        }
        else{
            cout << i << endl;
        }
    }


}