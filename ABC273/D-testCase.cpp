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
    ofstream outputfile("TestCase.txt");

    int H = myRnd32(2, 1000000000), W = myRnd32(2, 1000000000);
    int rs = myRnd32(1, H), cs = myRnd32(1, W);
    rs--;
    cs--;
    int tmpN = 200000;
    cout << "N [0, 2 * 10^5] = ";
    cin >> tmpN;
    int N = myRnd32(0, tmpN);

    outputfile << H << " " << W << " " << rs << " " << cs << "\n";
    outputfile << N << "\n";

    // cerr << "pointA" << endl;

    map<int, set<int>> Rwall, Cwall;

    // cerr << "pointB" << endl;

    set<pair<int, int>> checkSet;
    
    // cerr << "pointC" << endl;
    for(int i = 0; i < N; i++){
        int r = myRnd32(1, H), c = myRnd32(1, W);
        while(checkSet.count(make_pair(r, c))){
            r = myRnd32(1, H);
            c = myRnd32(1, W);
        }
        checkSet.insert(make_pair(r, c));
        // cin >> r >> c;

        outputfile << r << " " << c << "\n";

        r--;
        c--;
        Rwall[c].insert(r);
        Cwall[r].insert(c);
    }
    int tmpQ = 2 * 10^5;
    cout << "Q [1, 2 * 10^5] = ";
    cin >> tmpQ;
    int Q = myRnd32(1, tmpQ);
    outputfile << Q << "\n";

    string dTable = "LRUD";
    vector<char> dvec(Q);
    vector<int> lvec(Q);
    for(int i = 0; i < Q; i++){
        int dIndex = myRnd32(0, 3);
        char dtmp = dTable.at(dIndex);
        int ltmp = myRnd32(1, 1000000000);
        dvec.at(i) = dtmp;
        lvec.at(i) = ltmp;

        outputfile << dtmp << " " << ltmp << "\n";
    }

    outputfile.close();

    cout << "The work has done!" << "\n";
}