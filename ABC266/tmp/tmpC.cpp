#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const double PI = acos(-1);

double CalAng(double ux, double uy, double dx, double dy, double tx, double ty){
    double uVecX, uVecY, dVecX, dVecY;
    uVecX = ux - tx;
    uVecY = uy - ty;
    dVecX = dx - tx;
    dVecY = dy - ty;

    double ret = (atan2(uVecY, uVecX) - atan2(dVecY, dVecX)) * (180.0/PI);
    if(ret < 0)  ret += 360;

    return ret;
}

int main() {
    vector<double> A(2), B(2), C(2), D(2);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            if(i == 0)  cin >> A.at(j);
            if(i == 1)  cin >> B.at(j);
            if(i == 2)  cin >> C.at(j);
            if(i == 3)  cin >> D.at(j);
        }
    }

    // debug
    // for(int i = 0; i < 2; i++){
    //     cout << A.at(i) << B.at(i) << C.at(i) << D.at(i) << endl;
    // }

    bool OK = true;
    double angA, angB, angC, angD;
    angA = CalAng(D.at(0), D.at(1), B.at(0), B.at(1), A.at(0), A.at(1));
    angB = CalAng(A.at(0), A.at(1), C.at(0), C.at(1), B.at(0), B.at(1));
    angC = CalAng(B.at(0), B.at(1), D.at(0), D.at(1), C.at(0), C.at(1));
    angD = CalAng(C.at(0), C.at(1), A.at(0), A.at(1), D.at(0), D.at(1));

    // debug
    // cout << PI << endl;
    // cout << angA << endl;
    // cout << angB << endl;
    // cout << angC - 360.0 << endl;
    // cout << angD << endl;

    if(angA >= 180)  OK = false;
    if(angB >= 180)  OK = false;
    if(angC >= 180)  OK = false;
    if(angD >= 180)  OK = false;

    cout << (OK ? "Yes" : "No") << endl;

    return 0;
}