#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef _LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...)
#endif

int main() {
    int x = 1;
    string str = "Hello";
    int y = 124;
    double z = 3.1415;

    debug(x);
    debug();
    debug(x, y, z);
    debug(str);
    debug(x, y, z, str);
}