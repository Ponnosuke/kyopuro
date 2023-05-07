// AC
/*
vector<set<int>> vec(N);
N が大きすぎるとなんかメモリ確保できないよーって言われる


*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W, rs, cs;
    cin >> H >> W >> rs >> cs;
    rs--;
    cs--;
    int N;
    cin >> N;
    map<int, set<int>> Rwall, Cwall;
    for(int i = 0; i < N; i++){
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        Rwall[c].insert(r);
        Cwall[r].insert(c);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        char d;
        int l;
        cin >> d >> l;

        if(d == 'L'){
            auto itr = Cwall[rs].lower_bound(cs);
            if(Cwall[rs].empty()){
                cs = max(0, cs - l);
            }
            else if(itr == Cwall[rs].begin()){
                cs = max(0, cs - l);
            }
            else{
                cs = max(cs - l, *prev(itr) + 1);
            }
        }
        if(d == 'R'){
            auto itr = Cwall[rs].lower_bound(cs);
            if(Cwall[rs].empty()){
                cs = min(W - 1, cs + l);
            }
            else if(itr == Cwall[rs].end()){
                cs = min(W - 1, cs + l);
            }
            else{
                cs = min(cs + l, *itr - 1);
            }
        }
        if(d == 'U'){
            auto itr = Rwall[cs].lower_bound(rs);
            if(Rwall[cs].empty()){
                rs = max(0, rs - l);
            }
            else if(itr == Rwall[cs].begin()){
                rs = max(0, rs - l);
            }
            else{
                rs = max(rs - l, *prev(itr) + 1);
            }
        }
        if(d == 'D'){
            auto itr = Rwall[cs].lower_bound(rs);
            if(Rwall[cs].empty()){
                rs = min(H - 1, rs + l);
            }
            else if(itr == Rwall[cs].end()){
                rs = min(H - 1, rs + l);
            }
            else{
                rs = min(rs + l, *itr - 1);
            }
        }

        cout << rs + 1 << " " << cs + 1 << endl;
    }
}