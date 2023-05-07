#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;

    vector< pair<int, pair<i64, i64>> > seg(N+1);

    for(int i = 1; i <= N; i++){
        int t;
        cin >> t;
        i64 l, r;
        cin >> l >> r;

        seg.at(i) = make_pair(t, make_pair(l, r));
    }

    // debug
    /*
    cout <<  "t" << seg.at(1).first << endl;
    cout << "l" << seg.at(1).second.first << endl;
    cout << "r" << seg.at(1).second.second << endl;
    */

   i64 ans = 0;
   for(int i = 1; i <=N; i++){
    for(int j = i + 1; j <= N; j++){
        int t1, t2;
        t1 = seg.at(i).first;
        t2 = seg.at(j).first;

        i64 l1, l2, r1, r2;
        l1 = seg.at(i).second.first;
        l2 = seg.at(j).second.first;
        r1 = seg.at(i).second.second;
        r2 = seg.at(j).second.second;

        i64 commonNum;
        commonNum = min(r1, r2) - max(l1, l2);

        // debug
        /*
        cout << "(i,j) = " << i << " " << j << endl;
        cout << "commonNum = " << commonNum << endl;
        */

        if(commonNum > 0){
            ans++;
            
            // debug
            // cout << "rootA" << endl;
        }
        else if(commonNum == 0){
            if(r1 == l2){
                if((t1 == 1 || t1 == 3) && (t2 == 1 || t2 == 2))  ans++;

                // debug
                // cout << "rootB" << endl;
            }
            else if(r2 == l1){
                if((t1 == 1 || t1 == 2) && (t2 == 1 || t2 == 3))  ans++;

                // debug
                // cout << "rootC" << endl;
            }
        }

        // debug
        /*
        cout << "ans = " << ans << endl;
        cout << "t1 = " << t1 << " , " <<  "(l1, r1) = " << l1 << " " << r1 << endl;
        cout << "t2 = " << t2 << " , " <<  "(l2, r2) = " << l2 << " " << r2 << endl;
        */
    }
   }

   cout << ans << endl;
}