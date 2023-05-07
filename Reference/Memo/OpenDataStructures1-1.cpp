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

int main() {
    string str = "";
    string ch;
    while(cin >> ch){
        if(ch == "0"){
            break;
        }
        str += ch;
    }

    cout << str << '\n';
}

/*
input:
q                         
a
z
w
s
x
e
d
c
r
f
v
t
g
b
y
h
n
u
j
m
i
k
o
l
p
0

output:
qazwsxedcrfvtgbyhnujmikolp
*/