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

    int r = N-1, l = 0;
    int p = -1;
    vector<int> S(N, -1);
    for(int rep = 0; rep < 20; rep++){
        int mid = l + (r - l)/2;

        cout << "? " << mid + 1 << endl;
        int res;
        cin >> res;

        S.at(mid) = res;

        if(res == 0){
            if(S.at(mid+1) == 1){
                p = mid;
                break;
            }
            if(S.at(mid - 1) == 1){
                p = mid - 1;
                break;
            }

            l = mid;
        }
        else{
            if(S.at(mid+1) == 0){
                p = mid;
                break;
            }
            if(S.at(mid - 1) == 0){
                p = mid - 1;
                break;
            }

            r = mid;
        }


    }

    cout << "! " << p + 1 << endl;

    return 0;
}