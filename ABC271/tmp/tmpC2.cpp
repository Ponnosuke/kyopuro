#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    vector<i64> a(N);
    map<i64, i64> mp;
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        mp[a.at(i)]++;
    }

    // sort(a.begin(), a.end());

    i64 kan = 1;
    vector<bool> isSold(N, false);
    int index = 0;
    while(index < N){
        if(mp.count(kan)){
            if(mp.at(kan) > 0){
                mp.at(kan)--;
                kan++;
            }
        }
        else{
        }
    }
}