#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// i64
// L <= random <= R
i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}

// int
// L <= random <= R
int myRnd32(int L, int R){
    random_device seedGen;
    mt19937 rd(seedGen());

    int ret = rd() % R + 1;
    if(ret < L){
        ret = L;
    }

    return ret;
}

int main() {
    int H = myRnd32(2, 1000000000), W = myRnd32(2, 1000000000);
    int rs = myRnd32(1, H), cs = myRnd32(1, W);
    // cin >> H >> W >> rs >> cs;
    rs--;
    cs--;
    int N = myRnd32(0, 200000);
    // cin >> N;

    cout << H << " " << W << " " << rs << " " << cs << "\n";
    cout << N << "\n";

    // cerr << "pointA" << endl;

    vector<set<int>> Rwall(W);

    // cerr << "pointB" << endl;

    vector<set<int>> Cwall(H);

    // cerr << "pointC" << endl;

    set<pair<int, int>> checkSet;
    
    // cerr << "pointD" << endl;
    for(int i = 0; i < N; i++){
        int r = myRnd32(1, H), c = myRnd32(1, W);
        while(checkSet.count(make_pair(r, c))){
            r = myRnd32(1, H);
            c = myRnd32(1, W);
        }
        checkSet.insert(make_pair(r, c));
        // cin >> r >> c;

        cout << r << " " << c << "\n";

        r--;
        c--;
        Rwall.at(c).insert(r);
        Cwall.at(r).insert(c);
    }
    int Q = myRnd32(1, 200000);
    // cin >> Q;
    cout << Q << "\n";

    string dTable = "LRUD";
    vector<char> dvec(Q);
    vector<int> lvec(Q);
    for(int i = 0; i < Q; i++){
        int dIndex = myRnd32(0, 3);
        char dtmp = dTable.at(dIndex);
        int ltmp = myRnd32(1, 1000000000);
        dvec.at(i) = dtmp;
        lvec.at(i) = ltmp;

        cout << dtmp << " " << ltmp << "\n";
    }

    cout << "Ans:" << "\n";

    for(int i = 0; i < Q; i++){
        int dIndex = myRnd32(0, 3);
        char d = dvec.at(i);
        int l = lvec.at(i);

        if(d == 'L'){
            auto itr = Cwall.at(rs).lower_bound(cs);
            if(Cwall.at(rs).empty()){
                cs = max(0, cs - l);
            }
            else if(itr == Cwall.at(rs).begin()){
                cs = max(0, cs - l);
            }
            else{
                cs = max(cs - l, *prev(itr) + 1);
            }
        }
        if(d == 'R'){
            auto itr = Cwall.at(rs).lower_bound(cs);
            if(Cwall.at(rs).empty()){
                cs = min(W - 1, cs + l);
            }
            else if(itr == Cwall.at(rs).end()){
                cs = min(W - 1, cs + l);
            }
            else{
                cs = min(cs + l, *itr - 1);
            }
        }
        if(d == 'U'){
            auto itr = Rwall.at(cs).lower_bound(rs);
            if(Rwall.at(cs).empty()){
                rs = max(0, rs - l);
            }
            else if(itr == Rwall.at(cs).begin()){
                rs = max(0, rs - l);
            }
            else{
                rs = max(rs - l, *prev(itr) + 1);
            }
        }
        if(d == 'D'){
            auto itr = Rwall.at(cs).lower_bound(rs);
            if(Rwall.at(cs).empty()){
                rs = min(H - 1, rs + l);
            }
            else if(itr == Rwall.at(cs).end()){
                rs = min(H - 1, rs + l);
            }
            else{
                rs = min(rs + l, *itr - 1);
            }
        }

        cout << rs + 1 << " " << cs + 1 << endl;
    }
}