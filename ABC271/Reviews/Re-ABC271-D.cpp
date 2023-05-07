#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> a(N), b(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i) >> b.at(i);
    }

    vector<vector<bool>> dp(N+1, vector<bool>(S + 1, false));
    dp.at(0).at(0) = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= S; j++){
            if(dp.at(i).at(j)){
                if(j + a.at(i) <= S){
                    dp.at(i+1).at(j + a.at(i)) = true;
                }
                if(j + b.at(i) <= S){
                    dp.at(i+1).at(j + b.at(i)) = true;
                }
            }
        }
    }

    if(!dp.at(N).at(S)){
        cout << "No" << endl;
    }
    else{
        vector<char> ans(N);
        for(int i = N - 1; i >= 0; i--){
            bool OK = false;
            if(S - a.at(i) >= 0){
                if(dp.at(i).at(S - a.at(i))){
                    OK = true;
                }
            }

            if(OK){
                ans.at(i) = 'H';
                S -= a.at(i);
            }
            else{
                ans.at(i) = 'T';
                S -= b.at(i);
            }
        }

        cout << "Yes" << endl;
        for(auto ch : ans)  cout << ch;
        cout << endl;
    }
}