/*
    TLE
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int TEN_THOU = 10000;
const int FIELD_SIZE = 2 * TEN_THOU + 1;

vector<int> fieldx(FIELD_SIZE, 0), fieldy(FIELD_SIZE, 0);
// 1: OK, 0: NG

void dfsx(int x, int index, vector<int> A){
    if(index == A.size() - 1){
        fieldx.at(x + A.at(index)) = 1;
        fieldx.at(x - A.at(index)) = 1;
        return;
    }

    dfsx(x + A.at(index), index + 1, A);
    dfsx(x - A.at(index), index + 1, A);

    return;
}

void dfsy(int x, int index, vector<int> A){
    if(index == A.size() - 1){
        fieldy.at(x + A.at(index)) = 1;
        fieldy.at(x - A.at(index)) = 1;
        return;
    }
    
    dfsy(x + A.at(index), index + 1, A);
    dfsy(x - A.at(index), index + 1, A);

    return;
}

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    x += TEN_THOU;
    y += TEN_THOU;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    x -= A.at(0);
    vector<int> Ax, Ay;
    for(int i = 1; i < N; i++){
        if(i % 2 == 0){
            Ax.push_back(A.at(i));
        }
        else{
            Ay.push_back(A.at(i));
        }
    }
 
    dfsx(TEN_THOU, 0, Ax);
    dfsy(TEN_THOU, 0, Ay);
    bool OK1 = (fieldx.at(x) == 1);
    bool OK2 = (fieldy.at(y) == 1);

    if(OK1 && OK2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}