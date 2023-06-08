#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }
    int K;
    cin >> K;
    vector<int> x(K), y(K);
    for(int i = 0; i < K; i++){
        cin >> x.at(i) >> y.at(i);
        x.at(i)--;
        y.at(i)--;
    }
    int Q;
    cin >> Q;
    vector<int> p(Q), q(Q);
    for(int i = 0; i < Q; i++){
        cin >> p.at(i) >> q.at(i);
        p.at(i)--;
        q.at(i)--;
    }

    queue<int> que;
    vector<int> label(N, -1);
    int label_cnt = 0;
    for(int i = 0; i < N; i++){
        if(label.at(i) != -1){
            continue;
        }

        que.push(i);
        label.at(i) = label_cnt;
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int nxt : G.at(now)){
                if(label.at(nxt) != -1){
                    continue;
                }

                que.push(nxt);
                label.at(nxt) = label_cnt;
            }
        }

        label_cnt++;
    }

    set<pair<int, int>> st;
    for(int i = 0; i < K; i++){
        int xl = label.at(x.at(i));
        int yl = label.at(y.at(i));
        if(xl > yl){
            swap(xl, yl);
        }
        st.insert(make_pair(xl, yl));
    }

    for(int query = 0; query < Q; query++){
        int pl = label.at(p.at(query)), ql = label.at(q.at(query));
        if(pl > ql){
            swap(pl, ql);
        }

        if(st.count(make_pair(pl, ql))){
            cout << "No" << '\n';
        }
        else{
            cout << "Yes" << '\n';
        }
    }

    return 0;
}