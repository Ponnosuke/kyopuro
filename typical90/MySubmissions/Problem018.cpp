#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const double PI = acos(-1);

int main() {
    double T;
    cin >> T;
    double L, X, Y;
    cin >> L >> X >> Y;
    double Q;
    cin >> Q;
    vector<double> E(Q);
    for(int i = 0; i < Q; i++){
        cin >> E.at(i);
    }

    cout << fixed << setprecision(18);
    double omega = (2 * PI) / T;
    for(int i = 0; i < Q; i++){
        double fy = -(double)(L/2) * sin(omega * E.at(i));
        double fz = -(double)(L/2) * cos(omega * E.at(i)) + (double)(L/2);
        double distx = sqrt(X*X + (Y - fy)*(Y - fy));

        cout << atan2(fz, distx) * (180.0 / PI) << '\n';
    }

    return 0;
}