#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

double dist(int x1, int y1, int x2, int y2){
    int temp = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    return sqrt(temp);
}

int main() {
    int N;
    cin >> N;

    cout << fixed << setprecision(15);

    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++){
        cin >> x.at(i) >> y.at(i);
    }

    vector<vector<double>> distVec(N, vector<double>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            double tempDist = dist(x.at(i), y.at(i), x.at(j), y.at(j));
            distVec.at(i).at(j) = tempDist;
            distVec.at(j).at(i) = tempDist;
        }
    }

    vector<int> indexVec(N);
    for(int i = 0; i < N; i++) indexVec.at(i) = i; // sort済み

    double distSum = 0;
    do{
        for(int i = 0; i <= N - 2 ; i++){
            int index1 = indexVec.at(i);
            int index2 = indexVec.at(i+1);
            distSum += distVec.at(index1).at(index2);
        }
    } while (next_permutation(indexVec.begin(), indexVec.end()));

    int eleLen = 1;
    for(int i = 1; i <= N; i++)  eleLen *= i;

    cout << distSum / eleLen << endl;
}