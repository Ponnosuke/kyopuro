#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const double PI = acos(-1);

int main() {
    i64 T;
    cin >> T;
    i64 L, X, Y;
    cin >> L >> X >> Y;
    i64 Q;
    cin >> Q;
    vector<i64> E(Q);
    for(int i = 0; i < Q; i++){
        cin >> E.at(i);
    }

    cout << fixed << setprecision(18);
    double omega = (2.0 * PI) / T;
    for(int i = 0; i < Q; i++){
        double fy = -(L/2.0) * sin(omega * E.at(i));
        double fz = -(L/2.0) * cos(omega * E.at(i)) + (L/2.0);
        double distx = sqrt(X*X + (Y - fy)*(Y - fy));

        cout << atan2(fz, distx) * (180.0 / PI) << '\n';
    }

    return 0;
}