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

    // debug
    /*
    cout << "A" << endl;
    for(int i = 0; i <= h1; i++){
        for(int j = 0; j <= w1; j++){
            cout << A.at(i).at(j);
            if(j < w1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    // debug
    // cout << 1 << endl;

    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<i64>> B(h2, vector<i64>(w2));
    for(int i = 0; i < h2; i++){
        for(int j = 0; j < w2; j++){
            cin >> B.at(i).at(j);
        }
    }

    // debug
    /*
    cout << "B" << endl;
    for(int i = 0; i < h2; i++){
        for(int j = 0; j < w2; j++){
            cout << B.at(i).at(j);
            if(j < w2 - 1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    // debug
    // cout << 2 << endl;

    int popH = h1 - h2, popW = w1 - w2;

    vector<i64> existH1(h1, 1), existW1(w1, 1);
    for(int i = 0; i < popH; i++)  existH1.at(i) = 0;
    for(int i = 0; i < popW; i++)  existW1.at(i) = 0;

    // debug
    // cout << 3 << endl;

    bool OK = false;
    vector<vector<i64>> tmpA(h2, vector<i64>(w2));
    do{
        do{
            for(int i = 1; i <= h1; i++) A.at(i).at(0) = existH1.at(i-1);
            for(int i = 1; i <= w1; i++) A.at(0).at(i) = existW1.at(i-1);

            // debug
            /*
            for(auto x:existH1) cout << x;
            cout << endl;
            for(auto x:existW1) cout << x;
            cout << endl;
            */

            // debug
            // cout << 4 << endl;

            // debug
            /*
            cout << "A" << endl;
            for(int i = 0; i <= h1; i++){
                for(int j = 0; j <= w1; j++){
                    cout << A.at(i).at(j);
                    if(j < w1) cout << " ";
                }
                cout << endl;
            }
            */

            int indexH = 0, indexW = 0;
            for(int i = 1; i <= h1; i++){
                // debug
                // cout << 5 << endl;
                
                indexW = 0;
                if(A.at(i).at(0) == 0)  continue;
                for(int j = 1; j <= w1; j++){
                    if(A.at(0).at(j) == 0)  continue;
                    // debug
                    // cout << 6 << endl;

                    tmpA.at(indexH).at(indexW) = A.at(i).at(j);

                    // debug
                    // cout << "A.at(" << i << ").at(" << j << ") = " << A.at(i).at(j) << endl;
                    // cout << "tmpA.at(" << indexH << ").at(" << indexW << ") = " << tmpA.at(indexH).at(indexW) << endl;

                    // debug
                    // cout << 7 << endl;
                    indexW++;
                }
                indexH++;
            }

            // debug
            /*
            cout << "B" << endl;
            for(int i = 0; i < h2 ; i++){
                for(int j = 0; j < w2; j++){
                    cout << B.at(i).at(j);
                    if(j < w2 - 1) cout << " ";
                }
                cout << endl;
            }
            cout << "tmpA" << endl;
            for(int i = 0; i < h2 ; i++){
                for(int j = 0; j < w2; j++){
                    cout << tmpA.at(i).at(j);
                    if(j < w2 - 1) cout << " ";
                }
                cout << endl;
            }
            */


            if(B == tmpA) OK = true;


            // debug
            // if(OK) cout << "true" << endl << endl;
            // else cout << "false" << endl << endl;

        }while(next_permutation(existW1.begin(), existW1.end()));
    }while(next_permutation(existH1.begin(), existH1.end()));

    cout << (OK ? "Yes" : "No") << "\n";

}