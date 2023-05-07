/*
    WA
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }

    set<int> output;
    bool end = false;
    for(int i = N-1; i >= 0; i--){
        int now = P.at(i);

        while(now > 1){
            now--;
            if(output.count(now)){
                P.at(i) = now;
                output.erase(now);
                output.insert(now + 1);
                end = true;
                break;
            }
        }

        if(end){
            break;
        }
        else{
            output.insert(P.at(i));
        }
    }

    int index = N-1;
    for(auto ele : output){
        P.at(index) = ele;
        index--;
    }
    
    for(int i = 0; i < N; i++){
        cout << P.at(i);
        if(i < N-1){
            cout << " ";
        }
        else{
            cout << '\n';
        }
    }
}