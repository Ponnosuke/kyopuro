// For debug

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

constexpr int MIN = 0;
constexpr int MAX = 100;

int main() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);

    vector<int> nums(4);

    for (int n = 0; n < 4; ++n) {     
        nums.at(n) = distr(eng);
    }

    if(nums.at(0) == nums.at(1)){
        cout << "My name is Ponta." << endl;
        return 0;
    }
    if(nums.at(2) == nums.at(3)){
        cout << "I'm a tanuki." << endl;
        return 0;
    }
    if(nums.at(0) > nums.at(1)){
        swap(nums.at(0), nums.at(1));
    }
    if(nums.at(2) > nums.at(3)){
        swap(nums.at(2), nums.at(3));
    }

    for(int i = 0; i < 4; i++){
        if(i < 3) cout << nums.at(i) << " ";
        else cout << nums.at(i) << endl;
    }

    return 0;
}