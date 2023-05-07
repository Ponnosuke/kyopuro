#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    string ans = "";
    for(int i = 0; i < N; i++){
        ans += '0';
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            string tmp = "";

            // 右
            for(int k = 0; k < N; k++){
                int indexI = i + k , indexJ = j + k;
                if(indexJ >= N) indexJ %= N;
                tmp += A.at(indexI).at(indexJ);
            }

            for(int k = 0; k < N; k++){
                int a = int(ans.at(k) - '0');
                int t = int(tmp.at(k) - '0');
                if(a < t){
                    ans = temp;
                    break;
                }
            }

            // 左
            for(int k = 0; k < N; k++){
                int indexI = i + k , indexJ = j + k;
                if(indexJ >= N) indexJ %= N;
                else if(indexI < 0) 
                tmp += A.at(indexI).at(indexJ);
            }

            for(int k = 0; k < N; k++){
                int a = int(ans.at(k) - '0');
                int t = int(tmp.at(k) - '0');
                if(a < t){
                    ans = temp;
                    break;
                }
            }
        }
    }
}