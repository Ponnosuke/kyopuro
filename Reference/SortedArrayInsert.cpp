 /*
   C++ ソート済み配列に挿入
 */

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
 int main() {
 	vector<int> v = { 1, 3, 5, 7, 9 };
 	int x = 4;
 	v.insert(upper_bound(v.begin(), v.end(), x), x);
 	
  	for(auto i : v) {
 		cout << i << endl;
 	}
	// output
	/*
		1
		3
		4
		5
		7
		9
	*/
 }