#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    map<i64, i64> mp;
    set<i64> S;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        mp[a]++;
        S.insert(a);
    }

    i64 stockCnt = 0;
    for(auto ele : mp){
        stockCnt += ele.second - 1;
    }
    deque<i64> bookDeq;
    for(auto ele : S){
        bookDeq.push_back(ele);
    }

    i64 vol = 1;
    while((!bookDeq.empty()) || (stockCnt > 0)){  // この条件式が無いと RE になる ("true"だとダメ)
        if(S.count(vol)){
            bookDeq.pop_front();
            vol++;
        }
        else{
            if(stockCnt >= 2){
                stockCnt -= 2;
                vol++;
            }
            else if(stockCnt == 1){
                if(!bookDeq.empty()){
                    stockCnt -= 1;
                    bookDeq.pop_front();
                    vol++;
                }
                else{
                    break;
                }
            }
            else{
                if(bookDeq.size() >= 2){
                    bookDeq.pop_back();
                    bookDeq.pop_back();
                    vol++;
                }
                else{
                    break;
                }
            }
        }
    }

    vol--;

    cout << vol << endl;
}