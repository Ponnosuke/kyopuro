#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;

    vector<int> t(N);
    vector<i64> l(N), r(N);

    for(int i = 0; i < N; i++){
        int tTemp;
        i64 lTemp, rTemp;
        cin >> tTemp >> lTemp >> rTemp;

        t.at(i) = tTemp;
        l.at(i) = lTemp;
        r.at(i) = rTemp;
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){           
            int t1, t2;
            t1 = t.at(i);
            t2 = t.at(j);

            i64 l1, r1, l2, r2;
            l1 = l.at(i);
            r1 = r.at(i);
            l2 = l.at(j);
            r2 = r.at(j);

            i64 intersect = min(r1, r2) - max(l1, l2);

            // debug
            // cout << "(i, j) = " << i << " " << j << "\n";
            // cout << "interset = " << intersect << "\n";

            if(intersect > 0){
                ans++;

                // debug
                // cout << "routeA" << "\n";
            }
            else if(intersect == 0){
                if(l2 < l1){
                    swap(t1, t2);
                    swap(l1, l2);
                    swap(r1, r2);
                }

                if((t1 == 1 || t1 == 3) && (t2 == 1 || t2 == 2))  ans++;

                // debug
                // cout << "routeB" << "\n";
            }
        }
    }

    cout << ans << "\n";
}