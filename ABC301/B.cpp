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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> ans;
    ans.push_back(A.at(0));
    for(int i = 1; i < N; i++){
        if(abs(A.at(i-1) - A.at(i)) > 1){
            int add = 0;
            if(A.at(i-1) > A.at(i)){
                while(A.at(i-1) + add > A.at(i)){
                    add--;
                    ans.push_back(A.at(i-1) + add);
                }
            }
            else{
                while(A.at(i-1) + add < A.at(i)){
                    add++;
                    ans.push_back(A.at(i-1) + add);
                }
            }
        }
        else{
            ans.push_back(A.at(i));
        }
    }

    int aSize = ans.size();
    for(int i = 0; i < aSize; i++){
        cout << ans.at(i);

        if(i < aSize - 1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}