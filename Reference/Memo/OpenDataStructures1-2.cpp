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
    string S;
    set<string> strSet;
    while(getline(cin, S)){
        if(S == "0 0"){
            break;
        }

        strSet.insert(S);
    }

    for(auto str : strSet){
        cout << "str = " << str << '\n';
    }

    return 0;
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
0 0

output:
str = a
str = b
str = c
str = d
str = e
str = f
str = g
str = h
str = i
str = j
str = k
str = l
str = m
str = n
str = o
str = p
str = q
str = r
str = s
str = t
str = u
str = v
str = w
str = x
str = y
str = z
*/