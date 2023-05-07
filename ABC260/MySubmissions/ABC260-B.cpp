#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> A(N), B(N);
    for(auto &x : A)  cin >> x;
    for(auto &x : B)  cin >> x;

    // score, i +1する
    vector<pair<int, int>> Eng(N), Mat(N), Sum(N);

    vector<int> flag(N + 1,0); // 合格したら 1  数字はそのまま対応

    for(int i = 0; i < N; i++){
        Mat.at(i).first = A.at(i);
        Eng.at(i).first = B.at(i);
        Sum.at(i).first = A.at(i) + B.at(i);

        Mat.at(i).second = -(i + 1);
        Eng.at(i).second = -(i + 1);
        Sum.at(i).second = -(i + 1);
    }

    sort(Mat.begin(), Mat.end(), greater<pair<int, int>>());
    sort(Eng.begin(), Eng.end(), greater<pair<int, int>>());
    sort(Sum.begin(), Sum.end(), greater<pair<int, int>>());

    for(int i = 0; i < N; i++){
        Mat.at(i).second *= -1;
        Eng.at(i).second *= -1;
        Sum.at(i).second *= -1;
    }


    // debug
    /*
    cout << "Math" << endl;
    for(auto [l, r] : Mat){
        cout << l << " " << r << endl;
    }
    cout << "English" << endl;
    for(auto [l, r] : Eng){
        cout << l << " " << r << endl;
    }
    cout << "Sum" << endl;
    for(auto [l, r] : Sum){
        cout << l << " " << r << endl;
    }
    */

    

    for(int i = 0; i < X; i++){
        flag.at(Mat.at(i).second) = 1;
    }
    int j = 0, k = 0;
    while(j < Y){
        if(flag.at(Eng.at(k).second) == 1){
            k++;
            continue;
        }
        
        flag.at(Eng.at(k).second) = 1;
        j++;
        k++;
    }
    j = 0, k = 0;
    while(j < Z){
        if(flag.at(Sum.at(k).second) == 1){
            k++;
            continue;
        }
        
        flag.at(Sum.at(k).second) = 1;
        j++;
        k++;

        // debug
        /*
        cout << "Third loop" << endl;
        cout << "j = " << j << " " << "k = " << k << endl;
        */
    }


    for(int i = 1; i <= N; i++){
        if(flag.at(i) == 1){
            cout << i << endl;
        }
    }
}