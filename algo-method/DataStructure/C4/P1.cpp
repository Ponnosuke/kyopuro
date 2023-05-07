#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

struct Node{
    Node *nex;
    string value;
    Node(const string &value = "") :nex(NULL), value(value) {
    }
};

Node *nil;

void init(){
    nil = new Node();
    nil->nex = nil;
}

void insert(Node *v){
    v->nex = nil->nex;
    nil->nex = v;
}

int main() {
    init();

    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            string S;
            cin >> S;

            Node *v = new Node(S);
            insert(v);
        }
        if(type == 1){
            int k;
            cin >> k;

            Node *v = nil;
            for(int i = 0; i < k; i++){
                v = v->nex;
                if(v == nil){
                    break;
                }

                cout << v->value << " ";
            }
            cout << '\n';
        }
    }
}