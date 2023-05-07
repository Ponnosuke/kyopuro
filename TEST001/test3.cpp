#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
#define debug(X) std::cerr << #X << " = " << X << ", "
#define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
#else
#define debug(X) 3389
#define debugL(Y) 3391
#endif

// Um_nik さんのやつ、使い方わからん
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

int main() {
	int num1 = 100;
	double num2 = 3.131414;

	cout << "start" << endl;
	eprintf(num1, num2);
	cout << "end" << endl;

	return 0;
}