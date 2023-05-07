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
    vector<int> lx(N), ly(N), rx(N), ry(N);
    int maxX = -1, maxY = -1;
    for(int i = 0; i < N; i++){
        cin >> lx.at(i) >> ly.at(i) >> rx.at(i) >> ry.at(i);

        maxX = max(maxX, rx.at(i));
        maxY = max(maxY, ry.at(i));
    }

    vector<vector<int>> field(1001, vector<int>(1001, 0));
    for(int i = 0; i < N; i++){
        int tmpLx = lx.at(i), tmpLy = ly.at(i);
        int tmpRx = rx.at(i), tmpRy = ry.at(i);

        field.at(tmpLx).at(tmpLy) += 1;
        field.at(tmpRx).at(tmpLy) -= 1;
        field.at(tmpLx).at(tmpRy) -= 1;
        field.at(tmpRx).at(tmpRy) += 1;
    }

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            field.at(i+1).at(j) += field.at(i).at(j);
        }
    }
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            field.at(i).at(j+1) += field.at(i).at(j);
        }
    }

    debugWL(field);
    for(int y = maxY - 1; y >= 0; y--){
        for(int x = 0; x < maxX; x++){
            debug(field[x][y]);
        }
        debugWL();
    }

    vector<int> A(N+1, 0);
    for(int i = 0; i < maxX; i++){
        for(int j = 0; j < maxY; j++){
            A.at(field.at(i).at(j))++;
        }
    }

    for(int i = 1; i <= N; i++){
        cout << A.at(i) << '\n';
    }

    return 0;
}