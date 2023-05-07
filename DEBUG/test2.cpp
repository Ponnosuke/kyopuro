#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

void debugOut(){
    cerr << '\n';
    return;
}
template<typename Head, typename... Tail>
void debugOut(Head H, Tail... T){
    std::cerr << H << " ";
    debugOut(T...);
    return;
}
#ifdef LOCAL_DEBUG
    #define debug(...) debugOut(__VA_ARGS__)
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVV(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debugOut(__VA_ARGS__)
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(...)
    #define debugV(X)
    #define debugVV(...)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

#define MACRO (X, ...) std::cerr << X << __VA_OPT(',') << #__VA_ARGS__  << '\n'

int main() {
    int x = 1;
    string str = "Internet YAMERO";
    int y = 124;
    double z = 3.1415;

    debug(x, str, y, z);
    debugVV(x, str, y, z);

}