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
    deque<char> deq;
    deq.push_back('A');
    deq.push_back('B');
    deq.push_back('C');
    deq.pop_back();
    deq.push_back('X');
    deq.push_back('Y');
    deq.push_back('Z');
    deq.pop_back();

    for(int i = 0; i < deq.size(); i++){
        cout << deq[i];

        if(i < deq.size() - 1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}