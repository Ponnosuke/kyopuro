#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<i64>> A(h1 + 1, vector<i64>(w1 + 1, 1));
    for(int i = 1; i <= h1; i++){
        for(int j = 1; j <= w1; j++){
            cin >> A.at(i).at(j);
        }
    }

    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<i64>> B(h2, vector<i64>(w2));
    for(int i = 0; i < h2; i++){
        for(int j = 0; j < w2; j++){
            cin >> B.at(i).at(j);
        }
    }

    int popH = h1 - h2, popW = w1 - w2;
    vector<i64> existH1(h1, 1), existW1(w1, 1);
    for(int i = 0; i < popH; i++)  existH1.at(i) = 0;
    for(int i = 0; i < popW; i++)  existW1.at(i) = 0;

    bool OK = false;
    vector<vector<i64>> tmpA(h2, vector<i64>(w2));
    do{
        do{
            for(int i = 1; i <= h1; i++) A.at(i).at(0) = existH1.at(i-1);
            for(int i = 1; i <= w1; i++) A.at(0).at(i) = existW1.at(i-1);

            int indexH = 0, indexW = 0;
            for(int i = 1; i <= h1; i++){              
                if(A.at(i).at(0) == 0)  continue;

                indexW = 0;
                for(int j = 1; j <= w1; j++){
                    if(A.at(0).at(j) == 0)  continue;

                    tmpA.at(indexH).at(indexW) = A.at(i).at(j);
                    indexW++;
                }
                indexH++;
            }
            if(B == tmpA) OK = true;

        }while(next_permutation(existW1.begin(), existW1.end()));
    }while(next_permutation(existH1.begin(), existH1.end()));

    cout << (OK ? "Yes" : "No") << "\n";

    return 0;
}