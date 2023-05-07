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

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;

        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }

    vector<int> color(N, -1);
    queue<int> Q;
    Q.push(0);
    color.at(0) = 0;
    vector<int> cnt(2, 0);
    cnt.at(0) = 1;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();

        for(int nv : G.at(v)){
            if(color.at(nv) != -1){
                continue;
            }

            color.at(nv) = 1 - color.at(v);
            cnt.at(color.at(nv))++;
            Q.push(nv);
        }
    }

    debugWL(color);
    for(int i = 0; i < N; i++){
        debugV(i);
        debugVL(color.at(i));
    }
    debugWL();

    debugWL(point53);

    int index = 0, flag = 0;

    debugWL();
    debugV(cnt.at(0));
    debugVL(cnt.at(1));
    debugWL();

    if(cnt.at(0) >= cnt.at(1)){
        debugWL(routeA);
        while(flag < (N/2)){
            debugV(index);
            debugVL(flag);
            if(color.at(index) == 0){
                cout << index + 1;
                flag++;

                if(flag < (N/2)){
                    cout << " ";
                }
                else{
                    cout << '\n';
                }
            }
            
            index++;
        }
    }
    else{
        debugWL(routeB);
        while(flag < (N/2)){
            debugV(index);
            debugVL(flag);
            if(color.at(index) == 1){
                cout << index + 1;
                flag++;
                
                if(flag < (N/2)){
                    cout << " ";
                }
                else{
                    cout << '\n';
                }
            }
            
            index++;
        }
    }
}