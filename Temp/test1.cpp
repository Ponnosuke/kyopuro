#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

/*
    以下より引用

    組み合わせ (combination) を作成する - まくまくC/C++ノート 
    https://maku77.github.io/cpp/number/combination.html 
*/
template<class T>
void combination(const vector<T>& seed, int target_size, bool (*callback)(const vector<T>&)) {
    vector<int> indices(target_size);
    const int seed_size = seed.size();
    int start_index = 0;
    int size = 0;

    while (size >= 0) {
        for (int i = start_index; i < seed_size; ++i) {
            indices[size++] = i;
            if (size == target_size) {
                vector<T> comb(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = seed[indices[x]];
                }
                if (callback(comb)){
                    return;
                }
                break;
            }
        }
        --size;
        if (size < 0){
            break;
        }
        start_index = indices[size] + 1;
    }
}

///////////////// How to use

bool my_callback(const vector<int>& comb) {
    int n = comb.size();
    for (int i=0; i<n; ++i){
        cout << comb[i] << " ";
    }
    cout << endl;
    return false;
}

int main() {
    vector<int> vals;
    vals.push_back(1);
    vals.push_back(2);
    vals.push_back(3);
    vals.push_back(4);
    vals.push_back(5);

    combination(vals, 3, my_callback);
}