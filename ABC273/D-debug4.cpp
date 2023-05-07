#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 H, W;
    cin >> H >> W;
    i64 rs, cs;
    cin >> rs >> cs;
    rs--;
    cs--;
    i64 N;
    cin >> N;
    vector<i64> r(N), c(N);
    for(int i = 0; i < N; i++){
        cin >> r.at(i) >> c.at(i);
        r.at(i)--;
        c.at(i)--;
    }
    i64 Q;
    cin >> Q;
    vector<char> d(Q);
    vector<i64> l(Q);
    for(int i = 0; i < Q; i++){
        cin >> d.at(i) >> l.at(i);
    }

    vector<pair<i64, i64>> Rpair(N), Cpair(N);
    for(int i = 0; i < N; i++){
        Rpair.at(i) = make_pair(r.at(i), c.at(i));
        Cpair.at(i) = make_pair(c.at(i), r.at(i));
    }
    sort(Rpair.begin(), Rpair.end());
    sort(Cpair.begin(), Cpair.end());

    // debug
    // cout << "Rpair" << endl;
    // for(auto [p, q] : Rpair){
    //     cout << p << " " << q << endl;
    // }
    // cout << "Cpair" << endl;
    // for(auto [p, q] : Cpair){
    //     cout << p << " " << q << endl;
    // }

    vector<vector<i64>> Row(H), Clm(W);
    for(int i = 0; i < N; i++){
        pair<i64, i64> tmpR, tmpC;
        tmpR = Rpair.at(i);
        tmpC = Cpair.at(i);
        Row.at(tmpR.first).push_back(tmpR.second);
        Clm.at(tmpC.first).push_back(tmpC.second);

        // debug
        // cout << "tmpR ";
        // cout << tmpR.first << tmpR.second << endl;
        // cout << "tmpC ";
        // cout << tmpC.first << tmpC.second << endl;

    }
    
    // debug
    // cout << "pointA" << endl;

    i64 rnow = rs, cnow = cs;
    for(int i = 0; i < Q; i++){
        if(d.at(i) == 'L'){
            
            // debug
            // cout << "pointL" << endl;

            if(Row.at(rnow).size() == 0){
                cnow = max((cnow - l.at(i)), (i64)0);
            }
            else{
                i64 NG = Row.at(rnow).size();
                i64 OK = -1;
                while(abs(OK - NG) > 1){
                    i64 mid = (OK + NG) / 2;
                    if(Row.at(rnow).at(mid) < cnow){
                        OK = mid;
                    }
                    else{
                        NG = mid;
                    }
                }

                if(OK == -1){
                    cnow = max((cnow - l.at(i)), (i64)0);
                }
                else{
                    cnow = Row.at(rnow).at(OK) + 1;
                }
            }
        }
        if(d.at(i) == 'R'){

            // debug
            // cout << "pointR" << endl;

            if(Row.at(rnow).size() == 0){
                cnow = min((cnow + l.at(i)), W - 1);
            }
            else{
                i64 OK = Row.at(rnow).size();
                i64 NG = -1;
                while(abs(OK - NG) > 1){
                    i64 mid = (OK + NG) / 2;
                    if(Row.at(rnow).at(mid) > cnow){
                        OK = mid;
                    }
                    else{
                        NG = mid;
                    }
                }

                if(OK == Row.at(rnow).size()){
                    cnow = min((cnow + l.at(i)), W - 1);
                }
                else{
                    cnow = Row.at(rnow).at(OK) - 1;
                }
            }    
        }
        if(d.at(i) == 'U'){

            // debug
            // cout << "pointU" << endl;

            if(Clm.at(cnow).size() == 0){
                rnow = max(rnow - l.at(i), (i64)0);

                // debug
                // cout << "pointB" << endl;

            }
            else{
                i64 NG = Clm.at(cnow).size();
                i64 OK = -1;

                // debug
                /// cout << "pointC" << endl;

                while(abs(OK - NG) > 1){
                    i64 mid = (OK + NG) / 2;
                    if(Clm.at(cnow).at(mid) < rnow){
                        OK = mid;
                    }
                    else{
                        NG = mid;
                    }
                }

                // debug
                // cout << "pointD" << endl;
                // for(int ind = 0; ind < Clm.size(); ind++){
                //     cout << "ind = " << ind;
                //     for(auto x : Clm.at(ind)){
                //         cout << ", x = " << x << endl;
                //     }
                //     cout << endl;
                // }

                if(OK == -1){

                    // debug
                    // cout << "pointE" << endl;

                    rnow = max((rnow - l.at(i)), (i64)0);

                    // debug
                    // cout << "pointF" << endl;

                }
                else{

                    // debug
                    // cout << "pointG" << endl;

                    rnow = Clm.at(cnow).at(OK) + 1;

                    // debug
                    // cout << "pointH" << endl;
                }
            }
        }
        if(d.at(i) == 'D'){

            // debug
            // cout << "pointD" << endl;

            if(Clm.at(cnow).size() == 0){
                rnow = min(rnow + l.at(i), H - 1);
            }
            else{
                i64 OK = Clm.at(cnow).size();
                i64 NG = -1;
                while(abs(OK - NG) > 1){
                    i64 mid = (OK + NG) / 2;
                    if(Clm.at(cnow).at(mid) > rnow){
                        OK = mid;
                    }
                    else{
                        NG = mid;
                    }
                }

                if(OK == Clm.at(cnow).size()){
                    rnow = min((rnow + l.at(i)), W - 1);
                }
                else{
                    rnow = Clm.at(cnow).at(OK) - 1;
                }
            }
        }

        cout << rnow + 1 << " " << cnow + 1 << "\n";
    }

    // debug
    // vector<i64> test;
    // cout << test.size() << endl;
    // output: 0

}